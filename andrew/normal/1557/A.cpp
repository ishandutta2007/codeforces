#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

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
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 3e6;
const int M = 1e7;
const ll inf = 1e18;
const long long mod = 1e9 + 7;
const long long N = 3e5;


template <typename T> void vout(T s){cout << s << endl;exit(0);}


void solve(){
   int n;
   cin >> n;
   vector <int> a(n);

   ld ans = -1e18;
   ld sa, sb;
   sa = sb = 0;

   for(auto &i : a){
       cin >> i;
       sa += i;
   }

   sort(all(a));

   for(int i = 0; i < n - 1; i++){
       sb += a[i];
       sa -= a[i];
       ans = max(ans, sb / (i + 1) + sa / (n - i - 1));
   }

   cout << fixed << setprecision(7) << ans << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    //t = 1;

    while(t--){
        solve();
    }

    return 0;
}