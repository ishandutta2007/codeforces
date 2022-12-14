#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair <ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x) * (x)
#define sset ordered_set

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;

const ll MAXN = 1123456;
const ll N = 2e5;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl; exit(0);}

ll kol[MAXN], kol1[MAXN];
bool f[MAXN];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k, s;
    cin >> m >> k >> n >> s;

    vector <ll> a(m + 1);

    for(int i = 1; i <= m; i++)cin >> a[i];

    vector <ll> d;

    for(int i = 1; i <= s; i++){
        ll x;
        cin >> x;
        if(!kol[x])d.p_b(x);
        kol[x]++;
    }


    sort(all(d));

    ll l = 1, r = 1;

    vector <ll> ans;

    ll count = 0;

    ll sum1 = s;

    for(int l = 1; l <= m; l++){
        if(l > 1){
            ll x = a[l - 1];
            if(kol1[x] <= kol[x]){
                sum1++;
            }
            kol1[x]--;
        }
        while((l >= r) || (r <= m && (sum1 || r - l < k))){
            if(kol1[a[r]] < kol[a[r]]){
                sum1--;
            }
            kol1[a[r]]++;
            r++;
        }

        if(sum1)break;
        if(r - l < k)break;
        ll koll = (l - 1) / k + (m - r + 1) / k + 1;
        if(koll >= n){
            r--;
            for(int i = ((l - 1) / k) * k + 1; i < l; i++)f[i] = 1;
            for(int i = r + 1; i < m - ((m - r) / k) * k; i++)f[i] = 1;

            for(auto i : d)kol1[i] = 0;

            ll col = (r - l + 1) - k;
            for(int i = l; i <= r; i++){
                if(kol1[a[i]] < kol[a[i]])
                    kol1[a[i]]++;
                else if(col){
                    col--;
                    f[i] = 1;
                }
            }
             vector <ll> ans;
            for(int i = 1; i <= m; i++)if(f[i])ans.p_b(i);
            cout << ans.size() << "\n";
            for(auto i : ans)cout << i << " ";
            return 0;
        }
    }

    vout(-1);

    return 0;
}