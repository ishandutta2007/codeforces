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

bool f[MAXN], f1[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string a;
    cin >> a;
    ll pos = a.find("e");
    string b = a.substr(pos + 1);
    a.erase(pos);
    stringstream ss;
    ss << b;
    ll x;
    ss >> x;
    ll uk = a.find(".");
    while(x--){
        if(uk == a.size() - 1)a += "0";
        swap(a[uk], a[uk + 1]);
        uk++;
    }
    while(a[a.size() - 1] == '0')a.erase(a.size() - 1);
    if(uk == a.size() - 1)a.erase(a.size() - 1);
    cout << a << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}