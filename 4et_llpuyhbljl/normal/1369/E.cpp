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
const int Y = 200100;
const long long m = 1000000007;
vector<pair<int, int>>Ed[Y];
bool vis[Y];
vector<int>v;
int w[Y];
int32_t main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)cin >> w[i];
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        Ed[a].push_back({ b,i });
        Ed[b].push_back({ a,i });
    }
    priority_queue<pair<int, int>>q;
    for (int i = 1; i <= n; ++i) {
        w[i] -= (int)Ed[i].size();
        q.push({ w[i],i });
    }
    while (!q.empty()) {
        int r, b;
        tie(r, b) = q.top();
        q.pop();
        if (vis[b])continue;
        vis[b] = true;
        if (r < 0) {
            cout << "DEAD";
            return 0;
        }
        for (auto x : Ed[b]) {
            if (vis[x.first])continue;
            v.push_back(x.second);
            ++w[x.first];
            q.push({ w[x.first],x.first });
        }
    }
    reverse(v.begin(), v.end());
    cout << "ALIVE\n";
    for (auto x : v)cout << x << " ";
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