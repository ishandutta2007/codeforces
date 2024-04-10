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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++)cin >> a[i];

    ll ost = n + 1, sc = 0;;

    cout << n + 1 << "\n";

    for(int i = n; i >= 1; i--){
        ll x = a[i] + sc;
        x %= ost;
        ll val = (ost + i) - x;
        val %= ost;
        sc += val;
        cout << "1 " << i << " " << val << "\n";
    }

    cout << "2 " << n << " " << ost << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}