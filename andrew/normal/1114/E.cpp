#include <bits/stdc++.h>

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

ll val = 0;

ll gcd(ll a, ll b){
    while(a && b)if(a > b)a %= b; else b %= a;
    return a + b;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    ll l = 0, r = 1e9;

    while(l < r){
        ll c = (l + r) >> 1;
        if(c == l)c++;
        ll t;
        cout << "> " << c - 1 << endl;
        cin >> t;
        if(t == 1)l = c; else r = c - 1;
    }

    ll st = l;

    ll k = 0;

    ll op = 29;

    for(int i = 1; i <= 29ll; i++){
        ll pos = (rand() * rand()) % n + 1;
        cout << "? " << pos << endl;
        ll val;
        cin >> val;
        if(val != st)k = gcd(k, st - val);
    }

    cout << "! " <<  st - (n - 1) * k << " " << k << endl;


    return 0;
}