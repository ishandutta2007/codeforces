#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9 + 19;

struct Item {
    int next, prev, type;
    deque < int > * who;
};

vector < int > data;
int n;

void read() {
    string s;
    cin >> s;
    n = s.size();
    data.resize(n);
    for (int i = 0; i < n; i++)
        data[i] = s[i] == 'L'; 
}

deque < int > * merge(deque < int > * a, deque < int > * b) { 
    if (a == b) return a;
    if (a->size() < b->size())  {
        for (int i = (int)a->size() - 1; i >= 0; i--)
            b->push_front((*a)[i]);
        return b;
    }
    else {
        for (int i = 0; i < (int)b->size(); i++)
            a->push_back((*b)[i]);
        return a;
    }
}

int f(const vector < int > & res) {
    int cnt = 0;
    assert((int)res.size() == n);
    for (int i = 0; i < n - 1; i++)
        cnt += res[i + 1] < res[i];
    return cnt;
}

int smartSolve() {
    if (n == 1) {
        printf("0\n1\n");
        return 0;
    }

    vector < vector < int > > g;
    for (int i = 0; i < n; ) {
        int j = i;
        g.pb(vector < int > ());
        for (; i < n && data[i] == data[j]; i++)
            g.back().pb(i);
    }
    assert(g.size() > 1);    
    if (data[0] == data[n - 1]) {
        vector < int > tmp;
        for (auto x: g[0])
            g.back().pb(x);
        g[0] = g.back();
        g.pop_back();
    }
    int m = g.size();
    assert(m % 2 == 0); 
    vector < int > answer;
    //db(m);
    for (int tt = 0; tt < 2; tt++) {
        //db(tt);
        if (n % 2 == 1) {
            int sum = 0;
            for (int i = tt; i < m; i += 2)
                sum += g[i].size(); 
            if (sum * 2 < n)
                continue;
        }
        /*for (auto &x: g) {
            for (auto y: x)
                cerr << y << " ";
            cerr << endl;
        }*/


        vector < Item > b(m);
        for (int i = 0; i < m; i++) {
            b[i].next = (i + 1) % m;
            b[i].prev = (i - 1 + m) % m;
            b[i].type = i % 2;
            b[i].who = new deque < int > ();
            for (auto x: g[i])
                b[i].who->push_back(x);
        }
        int st = tt;
        vector < int > res;
        int curType = tt;
        for (; (int)res.size() < n;) {
            //db2("here", res.size());
            /*int tmp = st;
            for (; ;) {
                db(tmp);
                for (int i = 0; i < (int)b[tmp].who->size(); i++)
                    cerr << b[tmp].who->at(i) << " ";
                cerr << endl;
                tmp = b[tmp].next;
                if (tmp == st) break; 
            } */

            res.pb(b[st].who->back()); 
            assert(b[st].type == curType);
            curType ^= 1;
            b[st].who->pop_back();
            if (b[st].who->empty()) {
                int next = b[st].next;
                int prev = b[st].prev;  
                assert(b[next].type == b[prev].type);
                b[next].prev = b[prev].prev;
                b[b[prev].prev].next = next;
                b[next].who = merge(b[prev].who, b[next].who);
                st = next;
                //st = b[next].next;
            }
            else
                st = b[st].next;

            //else {
                //res.pb(b[st].who->back()); 
                //b[st].who->pop_back();
                //st = b[st].next;
            //}
        }
        if (answer.empty() || f(res) < f(answer))
            answer = res; 
    } 
    for (int i = 0; i < n - 1; i++)
        assert(data[answer[i]] != data[answer[i + 1]]);
    printf("%d\n", f(answer));
    for (auto x: answer)
        printf("%d ", x + 1);

    return f(answer);
}

int solve() {
    vector < int > use(n);
    int answer = n;
    for (int tt = 0; tt < 2; tt++) {
        use.assign(n, 0);
        int cnt = 0;
        int last = 0;
        int curType = tt;
        int goBack = 0;
        for (; cnt < n; ) {
            bool flag = 0;
            for (int i = 0; i < n; i++) {
                int pos = (last + i) % n;
                if (!use[pos] && data[pos] == curType) {
                    //db(pos);
                    flag = 1;
                    curType ^= 1;
                    use[pos] = 1;
                    goBack += (last > pos);
                    //db(goBack);
                    last = pos;
                    cnt++;
                    break;
                }

            }
            if (!flag)
                break;
        }
        //db2(cnt, n);
        if (cnt == n) {
            //db(goBack);
            answer = min(answer, goBack);
        }
    } 
    //db(answer);
    return answer;
}

void printAns(int x) {
    db2("answer", x);
}

void genTest() {
    n = 1 + rand() % 9;
    for (;;) {
        data.resize(n);
        for (int i = 0; i < n; i++)
            data[i] = rand() % 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += data[i];
        if (abs(cnt * 2 - n) <= 1)
            break;
    }
}



void printTest() {
    for (int i = 0; i < n; i++)
        cout << "LR"[data[i]];
    cout << endl;
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            //printAns(stupid());
            //printAns(solve());
            smartSolve();
        }
    }

    return 0;
}