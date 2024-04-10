#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;
    vector <ll> arr(n);
    ll l = 0, r = n - 1, ans = 0;
    for(int i = 0; i < n; i++)cin >> arr[i];
    while(l < r){
        if(arr[l] + arr[r] == 4){
            ans += 2 * min(a, b);
            l++,r--;
            continue;
        }
        if(arr[l] == 2){
            if(arr[r] == 1)ans += b; else ans += a;
        }else if(arr[r] == 2){
            if(arr[l] == 1)ans += b; else ans += a;
        }else if(arr[r] != arr[l])vout(-1);
        l++;r--;
    }
    if(l == r && arr[l] == 2)ans += min(a, b);
    vout(ans);
    return 0;
}