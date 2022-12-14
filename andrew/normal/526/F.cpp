#include <bits/stdc++.h>

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
#define sz(x) (int)x.size()

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 3e5 + 2;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

vector <int> a;
ll ans = 0;

ll L, R, kol;

int mp[3 * MAXN];
vector <int> le, ri, pmin, pmax, p1min, p1max;

void sol(int l, int r){
    if(l > r)return;
    if(l == r){
        ans++;
        return;
    }
    int m = (l + r) >> 1;
    for(int i = m + 1; i <= r; i++)ri.p_b(a[i]);
    for(int i = m; i >= l; i--)le.p_b(a[i]);


    for(auto i : le){
        pmin.p_b( (pmin.empty() ? i : min(pmin.back(), i)) );
        pmax.p_b( (pmax.empty() ? i : max(pmax.back(), i)) );
    }

    for(auto i : ri){
        p1min.p_b( (p1min.empty() ? i : min(p1min.back(), i)) );
        p1max.p_b( (p1max.empty() ? i : max(p1max.back(), i)) );
    }

    for(int i = 0; i < sz(ri); i++){
        L = p1min[i], R = p1max[i];
        kol = R - L + 1 - (i + 1);
        if(kol <= sz(le) && kol){
            if(L < pmin[kol - 1] && pmax[kol - 1] < R){
                ans++;
            }
        }
    }

    for(int i = 0; i < sz(le); i++){
        L = pmin[i], R = pmax[i];
        kol = R - L + 1 - (i + 1);
        if(kol <= sz(ri) && kol){
            if(L < p1min[kol - 1] && p1max[kol - 1] < R){
                ans++;
            }
        }
    }

    int uk = m, ukl = m;

    for(int i = m + 1; i <= r; i++){
        while(uk >= l && pmax[m - uk] < p1max[i - m - 1]){
            if(uk <= ukl){
                mp[uk - pmin[m - uk] + N]++;
            }
            uk--;
        }

        while(ukl >= l && pmin[m - ukl] > p1min[i - m - 1]){
            if(uk < ukl){
                mp[ukl - pmin[m - ukl] + N]--;
            }
            ukl--;
        }

        ans += mp[i - p1max[i - m - 1] + N];
    }

    for(int i = l; i <= m; i++)mp[i - pmin[m - i] + N] = 0;

    uk = m + 1;
    ukl = m + 1;

    for(int i = m; i >= l; i--){
        while(uk <= r && pmax[m - i] > p1max[uk - m - 1]){
            if(uk >= ukl){
                mp[p1min[uk - m - 1] + uk + N]++;
            }
            uk++;
        }

        while(ukl <= r && p1min[ukl - m - 1] > pmin[m - i]){
            if(uk > ukl){
                mp[p1min[ukl - m - 1] + ukl + N]--;
            }
            ukl++;
        }

        ans += mp[i + pmax[m - i] + N];
    }

    for(int i = m + 1; i <= r; i++)mp[i + p1min[i - m - 1] + N] = 0;

    le.clear();
    ri.clear();
    pmin.clear();
    pmax.clear();
    p1min.clear();
    p1max.clear();


    sol(l, m);
    sol(m + 1, r);

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a.resize(n + 1);

    for(int i = 1; i <= n; i++){
         ll y, x;
         cin >> y >> x;
         a[y] = x;
    }

    sol(1, n);

    cout << ans << "\n";

    return 0;
}