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

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

bool check(ll x, ll y, ll x1, ll y1){
    cout << "? " << x << " " << y << " " << x1 << " " << y1 << endl;
    string get;
    cin >> get;
    bool fl = 0;
    if(get == "YES")fl = 1;
    return fl;
}

int main(){
    ios_base :: sync_with_stdio(0);
    ll n, k;
    cin >> n;
    k = n - 1;
    string ans;
    ll x, y;
    x = y = 1;

    for(int i = 1; i < n; i++){
        if(check(x, y + 1, n, n)){
            ans += "R";
            y++;
        }else{
            ans += "D";
            x++;
        }
    }

    x = y = n;
    for(int i = 1; i < n; i++){
        if(check(1, 1, x - 1, y)){
            ans += "D";
            x--;
        }else{
            ans += "R";
            y--;
        }
    }

    reverse(ans.begin() + k, ans.end());
    cout << "! " << ans << endl;
    return 0;
}