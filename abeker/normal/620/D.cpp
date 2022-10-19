#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 2005;

int N, M;
int a[MAXN], b[MAXN];
vector < pair <ll, pii> > two;
int x = -1, y = -1, z = -1, w = -1;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) 
        scanf("%d", b + i);
}

void check(ll &ref, ll curr, int u, int v, int pos) {
    ll val = abs(2ll * two[pos].first - curr); 
    if (val >= ref) return;
    ref = val;
    x = u;
    z = v;
    y = two[pos].second.first;
    w = two[pos].second.second;
}

void solve() {
    ll sa = 0;
    for (int i = 0; i < N; i++)
        sa += (ll)a[i];
    ll sb = 0;
    for (int i = 0; i < M; i++)
        sb += (ll)b[i];
    
    ll sol = abs(sa - sb);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            ll curr = abs(sa - sb + 2ll * (b[j] - a[i]));
            if (curr >= sol) continue;
            sol = curr;
            x = i;
            y = j;
        }
    
    for (int i = 0; i < M; i++)
        for (int j = 0; j < i; j++)
            two.push_back(make_pair((ll)(b[i] + b[j]), pii(i, j)));
    sort(two.begin(), two.end());
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++) {
            ll curr = sb - sa + 2ll * (a[i] + a[j]);
            int pos = lower_bound(two.begin(), two.end(), make_pair((curr + 1) / 2, pii(-1, -1))) - two.begin();
            if (pos < two.size()) check(sol, curr, i, j, pos);
            if (pos > 0) check(sol, curr, i, j, --pos);
        }
        
    printf("%I64d\n", sol);
    vector <pii> res;
    if (x != -1) res.push_back(pii(x, y));
    if (z != -1) res.push_back(pii(z, w));
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", ++res[i].first, ++res[i].second);
}

int main() {
    load();
    solve();
    return 0;
}