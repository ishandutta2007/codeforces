#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 200005
#define INF 101111111111111
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
ll a[N][2], dp[N][2];
main(){
    FAST;
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll k = 0;k<2;k++){
            for(ll i = 0;i<n;i++){
                char c;
                cin >> c;
                a[i][k] = c-'0';
            }
        }
        if(a[0][0] >= 3){
            dp[0][0] = false;
            if(a[0][1] >= 3) dp[0][1] = true;
            else dp[0][1] = false;
        }
        else{
            dp[0][0] = true;
            dp[0][1] = false;
        }
        for(ll i = 1;i<n;i++){
            if(a[i][0] <= 2){
                dp[i][0] = dp[i-1][0];
            }else{
                dp[i][0] =(dp[i-1][1] && a[i][1] >= 3);
            }

            if(a[i][1] <= 2){
                dp[i][1] = dp[i-1][1];
            }else{
                dp[i][1] =(dp[i-1][0] && a[i][0] >= 3);
            }
        }
        if(dp[n-1][1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}