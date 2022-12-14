#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}



map < string, ll > mp;
unsigned long long hs[300][300], p = 307;
ll len[300][300];
ll dp[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, sum, ans;
    cin >> n;
    sum = n - 1;
    vector <string> a(n);
    vector <ll> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(mp.find(a[i]) == mp.end())mp[a[i]] = mp.size() + 1;
        b[i] = mp[a[i]];
        sum += a[i].size();
    }
    ans = sum;
    for(int i = 0; i < n; i++){
        ll p1 = 1, hss = 0, ln = 0;
        for(int j = i; j < n; j++){
            hss = (hss + p1 * b[j]);
            hs[i][j] = hss;
            ln += a[j].size() - 1;
            if(j - i + 1 > 1)ln++;
            p1 = (p * p1);
            len[i][j] = ln;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            for(int i1 = 1; i1 <= n; i1++)dp[i1] = 0;
            ll k = j - i + 1;
            for(int i1 = k; i1 <= n; i1++){
                 dp[i1] = dp[i1 - 1];
                 if(hs[i1 - k][i1 - 1] == hs[i][j])dp[i1] = dp[i1 - k] + 1;
            }
            if(dp[n] > 1){
                //cout << i << " " << j << " " << len[i][j] << " " << dp[n] << " " << dp[n] * len[i][j] << endl;
                ans = min(ans, sum - dp[n] * len[i][j]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}