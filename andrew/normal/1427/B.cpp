#include <bits/stdc++.h>

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
const ll M = 2e5;
const int inf = 1e8;
const ll mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool f = 0;
    int l = n;
    int t = n, ans = 0;
    vector <int> v;
    int lt = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'W'){
            if(lt != -1 && (i != 0 && s[i - 1] == 'L')){
                v.p_b(i - lt - 1);
            }
            ans += 1 + f;
            f = 1;
            t--;
            lt = i;
            l = min(l, i);
        }else{
            f = 0;
        }
    }
    sort(all(v));
    for(auto i : v){
        if(i <= k){
            k -= i;
            t -= i;
            ans += i * 2 + 1;
        }
        else{
            t -= k;
            ans += k * 2;
            k = 0;
        }
    }
    if(!k)fout(ans);
    if(t == n){
        k--;
        ans++;
        s[0] = 'W';
    }
    if(s[0] == 'L')t--;
    int c = min(t, k);
    ans += 2 * c;
    k -= c;
    t -= c;
    if(s[0] == 'L')t++;
    if(t && k && n > 1)ans += 2;
    cout << ans << "\n";
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}