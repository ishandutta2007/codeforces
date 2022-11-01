#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define sz(x)                       (ll) x.size()
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second

ll Pow(ll a, ll b, ll md) {
    if (b == 0)
        return 1;
    if (b & 1)
        return a * Pow(a * a % md, b / 2, md) % md;
    return Pow(a * a % md, b / 2, md) % md;
}

const ll MAXN = 5e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7;
ll dist[MAXN / 10][MAXN], D, Sr;
pll par[MAXN / 10][MAXN];

void BFS(ll i = 0, ll j = 0) {
    memset(dist, 63, sizeof dist);
    dist[0][0] = 0;
    queue<pll> Q;
    Q.emplace(0, 0);
    while (sz(Q)) {
        tie(i, j) = Q.front();
        Q.pop();
        for (ll k = 0; k < 10; k++) {
            ll x = (i * 10 + k) % D, y = j + k;
            if (y >= MAXN) continue;
            if (dist[x][y] > dist[i][j] + 1) {
                dist[x][y] = dist[i][j] + 1;
                par[x][y] = {i, k};
                Q.emplace(x, y);
            }
        }
    };
}

void Print() {
    ll x = 0, y = Sr;
    vector<ll> ans;
    while (x != 0 || y != 0) {
        ans.push_back(par[x][y].S);
        ll X = par[x][y].S;
        x = par[x][y].F, y -= X;
    }
    reverse(all(ans));
    for (ll X : ans) printf("%lld", X);
    printf("\n");
}

int main() {
    scanf("%lld%lld", &D, &Sr);
    BFS();
    if (dist[0][Sr] > INF / 10) return !printf("-1\n");
    Print();
    return 0;
}