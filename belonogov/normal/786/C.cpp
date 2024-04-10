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
#include <random>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int F = 200;

int n;
vector<int> a;

void read() {
    scanf("%d", &n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
}


vector<int> slow(int k) {
    vector<int> res(n); 
    vector<int> cnt(n);
    int ver = 0;
    for (int i = 1; i <= k; i++) {
        int answer = 0; 
        int pos = 0;
        for (;pos < n;) {
            int can = i;
            ver++; 
            answer++;
            for (; pos < n; pos++) {
                if (cnt[a[pos]] != ver) {
                    if (can > 0) {
                        cnt[a[pos]] = ver;
                        can--;
                    }
                    else
                        break;
                }
            }
            //db(answer);
        }
        //exit(0);
        res[i - 1] = answer;
    }
    return res;
}

struct SuperUse {
    int cnt[N];
    //int ver[N];
    //int v;
    int sz;
    SuperUse() {
        clear();
    }
    //void flush() {
        //v++;
    ///}
    void add(int x) {
        //if (ver[x] != v) {
            //ver[x] = v;
            //cnt[x] = 0;
        //}
        if (cnt[x] == 0) {
            sz++;
        }
        cnt[x]++;
    }
    int ifadd(int x) {
        return sz + (cnt[x] == 0);
    }

    void rem(int x) {
        //assert(ver[x] == v);
        assert(cnt[x] > 0);
        cnt[x]--;
        sz -= cnt[x] == 0;
    }
    void clear() {
        memset(cnt, 0, sizeof cnt);
        sz = 0;
    }
};

SuperUse b[F];

vector<int> smart(int bound) {
    //db(bound);
    assert(bound * F >= n);    
    vector<int> l;
    vector<int> r;
    int pos = 0;
    int cur = 0;
    for (; pos < n; cur++) {
        b[cur].clear();
        l.pb(pos);
        for (;pos < n;) {
            if (b[cur].ifadd(a[pos]) <= bound) {
                b[cur].add(a[pos]);
                pos++;
            }
            else
                break;
        }
        r.pb(pos);
    }  
    //db(pos);
    //db(b[0].sz);
    //db(b[0].ifadd(0));

    vector<int> answer(n);

    //db(cur);
    for (int i = bound; i <= n; i++) {
        answer[i - 1] = cur;
        //if (i == n) break;
        int prev = 0;
        for (int j = 0; j < cur; j++) {
            assert(prev <= n);
            if (prev == n) {
                cur = j;
                break;
            }
            for (; l[j] < prev;) {
                if (r[j] == l[j]) {
                    assert(b[j].sz == 0);
                    b[j].add(a[r[j]++]);
                }
                b[j].rem(a[l[j]++]);
            }  
            for (; r[j] < n && b[j].ifadd(a[r[j]]) <= (i + 1); ) {
                b[j].add(a[r[j]++]);
            }
            prev = r[j];
        }
    }
    /*for (auto x: answer)
        cerr << x << " ";
    cerr << endl;

    exit(0);*/

    return answer;
}

vector<int> solve() {
    int bound = sqrt(n * 5);
    auto r1 = slow(bound); 
    auto r2 = smart(bound);
    for (int i = 0; i < bound; i++)
        r2[i] = r1[i];
    //r2[0]++;
    return r2;
}


void printAns(vector<int> tmp) {
    for (auto x: tmp)
        printf("%d ", x);
    puts("");
}

void genTest() {
    n = rand() % (int)1e5+ 1;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = rand() % n;
}

void printTest() {
    cout << n << endl;
    for (auto x: a)
        cout << x + 1 << " ";
    cout << endl;
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        genTest();
        //printTest();
        auto r1 = solve();
       /*for (int i = 0; i < 1000; i++)
            cerr << r1[i] << " ";
        cerr << endl;*/
        return;
        //auto r2 = smart(1);
        //assert(r1 == r2);
    }

}

int main(){
#define TASK "C"
#ifdef HOME 
    assert(freopen(TASK".in", "r", stdin));
    //assert(freopen(TASK".out", "w", stdout));
#endif
    if (1) {
        read();
        printAns(solve());
    }
    else {
        stress();
    }


    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}