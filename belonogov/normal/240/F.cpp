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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;
const int ALF = 26;

struct Tree {
    vector < int > data;
    vector < int > upd;
    void init(int n) {
        data.resize(n * 4);
        upd.resize(n * 4, -1);
    }
    void push(int v, int ll, int rr) {
        if (upd[v] != -1) {
            upd[v * 2 + 1] = upd[v];
            upd[v * 2 + 2] = upd[v];
            data[v * 2 + 1] = upd[v] * ((ll + rr) / 2 - ll);
            data[v * 2 + 2] = upd[v] * (rr - (ll + rr) / 2);
            upd[v] = -1;
        }
    }

    void setVal(int v, int ll, int rr, int l, int r, int val) {
        if (ll >= r || l >= rr) return;
        if (l <= ll && rr <= r) {
            upd[v] = val;
            data[v] = val * (rr - ll);
            return;
        }
        push(v, ll, rr);
        setVal(v * 2 + 1, ll, (ll + rr) / 2, l, r, val);
        setVal(v * 2 + 2, (ll + rr) / 2, rr, l, r, val);
        data[v] = data[v * 2 + 1] + data[v * 2 + 2];
    }
    int getSum(int v, int ll, int rr, int l, int r) {
        if (ll >= r || l >= rr) return 0;
        if (l <= ll && rr <= r) return data[v];
        push(v, ll, rr);
        return getSum(v * 2 + 1, ll, (ll + rr) / 2, l, r) +
               getSum(v * 2 + 2, (ll + rr) / 2, rr, l, r);
    }
    void go(int v, int ll, int rr, vector < int > & answer, int id) {
        if (ll + 1 == rr) {
            if (data[v])
                answer[ll] = id;
            return;
        }
        push(v, ll, rr);
        go(v * 2 + 1, ll, (ll + rr) / 2, answer, id);
        go(v * 2 + 2, (ll + rr) / 2, rr, answer, id);
    }
};

int n, m;
char s[N];
int a[N];
Tree tree[ALF];

void read() {
    scanf("%d%d", &n, &m);
    scanf("%s", s);
}

void solve() {
    for (int i = 0; i < ALF; i++)
        tree[i].init(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a';
        tree[a[i]].setVal(0, 0, n, i, i + 1, 1);
    }

    for (int i = 0; i < m; i++) {
        //db(i);
        int l, r;
        scanf("%d%d", &l, &r); l--;
        vector < int > tmp; 
        //db2(l, r);
        for (int j = 0; j < ALF; j++)
            tmp.pb(tree[j].getSum(0, 0, n, l, r));
        int cntOdd = 0;
        for (int j = 0; j < ALF; j++)
            cntOdd += tmp[j] % 2 == 1;
        int st1 = -1, st2 = -1;

        //for (auto x: tmp)
            //cerr << x << " ";
        //cerr << endl;
        if (cntOdd == (r - l) % 2) {
            for (int j = 0; j < ALF; j++)
                tree[j].setVal(0, 0, n, l, r, 0);
        }
        else 
            continue;

        if (cntOdd == 0 && (r - l) % 2 == 0) {
            st1 = l;
            st2 = (l + r) / 2;
        }
        if (cntOdd == 1 && (r - l) % 2 == 1) {
            st1 = l; 
            st2 = (l + r + 1) / 2;
            int posOdd = -1;
            for (int j = 0; j < ALF; j++)
                if (tmp[j] % 2 == 1)
                    posOdd = j;
            tmp[posOdd]--;
            tree[posOdd].setVal(0, 0, n, st2 - 1, st2, 1);
        }

        for (int j = 0; j < ALF; j++) {
            if (tmp[j] == 0) continue;
            //cerr << "set j l r: " << j << " " << st1 << " " << st1 + tmp[j] << endl;
            tree[j].setVal(0, 0, n, st1, st1 + tmp[j] / 2, 1);
            st1 += tmp[j] / 2;
        }
        for (int j = ALF - 1; j >= 0; j--) {
            if (tmp[j] == 0) continue;
            tree[j].setVal(0, 0, n, st2, st2 + tmp[j] / 2, 1);
            st2 += tmp[j] / 2;
        }
    }
    vector < int > answer(n, -1); 
    for (int j = 0; j < ALF; j++)
        tree[j].go(0, 0, n, answer, j);

    //for (auto x: answer)
        //cerr << x << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++) {
        assert(answer[i] != -1);
        printf("%c", char(answer[i] + 'a'));
    }

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}