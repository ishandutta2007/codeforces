#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<random>
using namespace std;
int gcd(int i, int j) {
    if (j == 0)return i;
    else return gcd(j, i % j);
}
template<typename T> inline T getint() {
    T val = 0;
    char c;

    bool neg = false;
    while ((c = getchar()) && !(c >= '0' && c <= '9')) {
        neg |= c == '-';
    }

    do {
        val = (val * 10) + c - '0';
    } while ((c = getchar()) && (c >= '0' && c <= '9'));

    return val * (neg ? -1 : 1);
}
const long long INF = 10000000;
const int Y = 1100;
const long long mod = 1000000007;
vector<int>Ed[Y];
int dp[Y];
int pp[Y];
int cost[Y];
int dep[Y];
void dfs1(int i, int p) {
    for (auto x : Ed[i]) {
        if (x == p)continue;
        dp[x] = dp[i] + 1;
        pp[x] = i;
        dfs1(x, i);
    }
}
int MD(int n) {
    dp[1] = 0;
    dfs1(1, 0);
    int mx = 0, v = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > mx) {
            mx = dp[i];
            v = i;
        }
    }
    dp[v] = 0;
    dfs1(v, 0);
    mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > mx) {
            mx = dp[i];
            v = i;
        }
    }
    int gr = mx / 2;
    while (dp[v] != gr)v = pp[v];
    return v;
}
void bld() {
    for (int i = 0; i < Y; ++i) {
        Ed[i].clear();
        dep[i] = 0;
        cost[i] = INF;
    }
}
void dfs(int i, int p) {
    for (auto x : Ed[i]) {
        if (x == p)continue;
        else {
            dep[x] = dep[i] + 1;
            dfs(x, i);
        }
    }
}
pair<int, int>qw(vector<int> q) {
    cout << "? " << q.size();
    for (auto x : q)cout << " " << x;
    cout << endl;
    int a, d;
    cin >> a >> d;
    if (a == -1)exit(0);
    return { a,d };
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        bld();
        int n;
        cin >> n;
        for (int i = 1; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            Ed[a].push_back(b);
            Ed[b].push_back(a);
        }
        dfs(MD(n), 0);
        vector<int>q;
        for (int i = 1; i <= n; ++i)q.push_back(i);
        int b, d;
        int s, f;
        tie(b, d) = qw(q);
        s = b;
        b = dep[b];
        int e = 0;
        for (int i = 1; i <= n; ++i)e = max(e, dep[i]);
        ++e;
        while (b + 1 != e) {
            q.clear();
            int mid = (b + e) / 2;
            for (int i = 1; i <= n; ++i)if (dep[i] == mid)q.push_back(i);
            int ta, td;
            tie(ta, td) = qw(q);
            if (td == d) {
                b = mid;
                s = ta;
            }
            else {
                e = mid;
            }
        }
        cost[s] = 0;
        queue<int>qq;
        qq.push(s);
        while (!qq.empty()) {
            int h = qq.front();
            qq.pop();
            for (auto x : Ed[h]) {
                if (cost[x] == INF) {
                    cost[x] = cost[h] + 1;
                    qq.push(x);
                }
            }
        }
        q.clear();
        for (int i = 1; i <= n; ++i) {
            if (cost[i] == d) {
                q.push_back(i);
            }
        }
        tie(f, d) = qw(q);
        cout << "! " << f << " " << s << endl;
        string ss;
        cin >> ss;
        if (ss == "Incorrect") {
            return 0;
        }
    }
    return 0;
}
//freopen("painter.in", "r", stdin);
//freopen("painter.out", "w", stdout);
/*
3
ooo
o..
o..
*/
/* Fri May 15 2020 19:54:42 GMT+0300 (MSK) */

/* Wed May 20 2020 19:33:48 GMT+0300 (MSK) */