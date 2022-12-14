#include <bits/stdc++.h>

#define fi first
#define se second
#define pll pair<ll, ll>

using namespace std;
typedef long long ll;

const ll MAXN = 1123456;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    ll mxa = -1e18, mxb = -1e18;

    while(n--){
        char t;
        cin >> t;
        if(t == '+'){
            ll a, b;
            cin >> a >> b;
            if(a > b)swap(a, b);
            mxa = max(mxa, a);
            mxb = max(mxb, b);
        }else{
            string ans = "NO";
            ll a, b;
            cin >> a >> b;
            if(a > b)swap(a, b);

            if(mxa <= a && mxb <= b)ans = "YES";
            cout << ans << "\n";
        }

    }

    return 0;
}