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

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int T = 20;
const int INF = 1e9;

int n, k;
int a[N];
int step[N];
pair < int, int > g[T][N];
vector < int > add[N];
vector < int > sub[N];
int st[N];
long long sum[N];
int cnt[N];


pair < int, int > getMax(int l, int r) {
    int len = r - l;
    return max(g[st[len]][l], g[st[len]][r - (1 << st[len])]);
}
long long getSum(int l, int r) {
    return sum[r] - sum[l];
}

void calc(int l, int r) {
    if (l >= r) return;
    //cerr << "call\n";
    //db2(l, r);
    auto res = getMax(l, r);    
    int x = res.sc;    
    //db(x);
    int len = r - l;
    //db(x);
    if ((x - l) * 2 < len) {
        //db2(l, x);
        //cerr << "==========first case\n";
        for (int i = l; i <= x; i++) {
            //db(i);
            long long s = (k - getSum(i, x) % k + sum[x + 1]) % k;
            //b.pb(query(r, s, 1));
            //b.pb(query(x + 1, s, -1));
            //b[r].pb(mp(s, 1));
            //b[x + 1].pb(mp(s, -1));
            //db(s);
            //db2(x, r);
            //add[r + 1].pb(s);
            add[r + 1].pb(s);
            sub[x + 1].pb(s);
        }
        //b.pb(query(r, sum[x] % k, 1));
        //b.pb(query(x + 2, sum[x] % k, -1));
        //b[r].pb(mp(sum[x] % k, 1));
        //b[x + 2].pb(mp(sum[x] % k, -1));
    }
    else {
        //db2(x, r);
        //cerr << "==========second case\n";
        for (int i = x; i < r; i++) {
            long long s = (getSum(x + 1, i + 1) + sum[x]) % k;
            //b.pb(query(l, s, -1));
            //b.pb(query(x, s, 1));
            //b[l].pb(mp(s, -1));
            //b[x].pb(mp(s, 1));
            //db(s);
            //db2(l, x);
            add[x + 1].pb(s);
            sub[l].pb(s);
        }
        //b.pb(query(l, (k - sum[x]) % k, -1));
        //b.pb(query(x - 1, (k - sum[x]) % k, 1));
        //b[l].pb(mp((k - sum[x]) % k, -1));
        //b[x - 1].pb(mp((k  - sum[x]) % k, 1));
    }
    calc(l, x);
    calc(x + 1, r);
}

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}


void solve() {
    for (int i = 0; i < n; i++)
        g[0][i] = mp(a[i], i);

    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + a[i];

    for (int j = 1; j < T; j++)
        for (int i = 0; i + (1 << j) <= n; i++) 
            g[j][i] = max(g[j - 1][i], g[j - 1][i + (1 << (j - 1))]);

    for (int i = 2; i <= n; i++)
        st[i] = st[i / 2] + 1;
     
    calc(0, n);
    long long answer = 0;
    //for (int i = 0; i <= n; i++)
        //cerr << a[i] << 
    for (int i = 0; i <= n + 1; i++) {

        for (auto x: sub[i])
            answer -= cnt[x];
        for (auto x: add[i])
            answer += cnt[x];
    
        cnt[sum[i] % k]++;
    }
    cout << answer - n << endl;
    //cout << answer << endl;
}
void printAns() {

}

void stress() {

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
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}