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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n, m;
    cin >> n;
    m = n * 2;
    vector <ll> a(m);
    for(int i = 0; i < m; i++)cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < m; i += 2){
        ll j;
        for(j = i + 1; j < m; j++)if(a[j] == a[i])break;
        while(j != i + 1){
            swap(a[j], a[j - 1]);
            j--;
            ans++;
        }
    }
    vout(ans);
    return 0;
}