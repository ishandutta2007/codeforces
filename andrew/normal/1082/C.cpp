#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}

vector <ll> v[MAXN];

ll uk[MAXN], arr[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m;
    cin >> n >> m;

    set <ll> a;

    ll ans, sc;
    ans = sc = 0;

    for(int i = 1; i <= n; i++){
        ll x, val;
        cin >> x >> val;
        v[x].p_b(val);
        a.insert(x);
    }

    for(int i = 1; i <= n; i++){
        sort(all(v[i]));
        reverse(all(v[i]));
    }

    for(int i = 1; i <= n; i++){
        vector <ll> c;
        for(auto j : a){
            if(uk[j] == v[j].size()){
                c.p_b(j);
                sc -= arr[j];
                continue;
            }
            arr[j] += v[j][uk[j]];
            sc += v[j][uk[j]];
            uk[j]++;
            if(arr[j] < 0){
                sc -= arr[j];
                c.p_b(j);
            }
        }
        ans = max(ans, sc);
        for(auto j : c)a.erase(j);
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}