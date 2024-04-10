#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll block;

struct Query {
	int l, r, idx;

	inline pair<int, int> toPair() const {
		return make_pair(l / block, ((l / block) & 1) ? -r : +r);
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.toPair() < b.toPair();
}

ll col[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    while(block * block < n)block++;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    vector <ll> res(m);

    vector <Query> c(m);

    for(int i = 0; i < m; i++){
        cin >> c[i].l >> c[i].r;
        c[i].idx = i;
    }

    sort(c.begin(), c.end());

    ll ans = 0;

    for(int i = c[0].l; i <= c[0].r; i++){
        if(a[i] > n)continue;
        if(col[a[i]] == a[i])ans--;
        col[a[i]]++;
        if(col[a[i]] == a[i])ans++;
    }

    ll l = c[0].l, r = c[0].r;

    res[c[0].idx] = ans;

    for(auto kek : c){
        if(kek.idx == c[0].idx)continue;

        while(l < kek.l){
            if(a[l] > n){
                l++;
                continue;
            }
            if(col[a[l]] == a[l])ans--;
            col[a[l]]--;
            if(col[a[l]] == a[l])ans++;
            l++;
        }

        while(l > kek.l){
            if(a[l - 1] > n){
                l--;
                continue;
            }
            if(col[a[l - 1]] == a[l - 1])ans--;
            col[a[l - 1]]++;
            if(col[a[l - 1]] == a[l - 1])ans++;
            l--;
        }

        while(r < kek.r){
            if(a[r + 1] > n){
                r++;
                continue;
            }
            if(col[a[r + 1]] == a[r + 1])ans--;
            col[a[r + 1]]++;
            if(col[a[r + 1]] == a[r + 1])ans++;
            r++;
        }

        while(r > kek.r){
            if(a[r] > n){
                r--;
                continue;
            }
            if(col[a[r]] == a[r])ans--;
            col[a[r]]--;
            if(col[a[r]] == a[r])ans++;
            r--;
        }
        res[kek.idx] = ans;
    }

    for(auto i : res)cout << i << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}