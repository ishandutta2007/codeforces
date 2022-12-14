#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>

#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define m_p make_pair
#define p_b push_back
#define sqr(x) (x) * (x)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
const ll N = 2e5;
const ll MAXN = 1123456;

template <typename T> void vout(T s){cout << s << endl; exit(0);}


void solve(){
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n + 1), c(n + 1);

    vector <ll> kol(n + 1);

    set <ll> s;
    vector <ll> st;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        st.p_b(a[i]);
    }
    sort(all(st));

    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(all(st), a[i]) - st.begin() + 1;
        s.insert(a[i]);
    }

    vector <ll> pos(n + 1);

    for(int i = 1; i <= n; i++)pos[a[i]] = i;

    ll ans = 1;

    for(int i = 2; i <= n; i++)if(pos[i] - 1 != pos[i - 1])ans++;

    if(ans <= k){
    cout << "YES\n";
    }else{
        cout << "NO\n";
    }

}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}