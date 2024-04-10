//! Lets Get it
#include<bits/stdc++.h>
using namespace std;

typedef double                      ld;
typedef long long                   ll;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<string , string>       pss;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define F                           first
#define S                           second
#define sep                         ' '
#define endl                        '\n'
#define file_io                     freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl , 0;
#define pb                          push_back

const ll MXN = 3e3 + 10;
const ll MXM = (1LL << 18) + 10;
const ll MX5 = 1e5 + 10;
const ll MX6 = 1e6 + 10;
const ll LOG = 20;
const ll INF = 8e18;
const ld eps = 1e-9;
const ll MOD = 1e9 + 9; //998244353;

ll power(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));
}
ll bmm(ll a,ll b){
    return (a%b==0 ? b : bmm(b,a%b));
}
string base2(ll n){
    string a="";while(n>=2){a+=(char)(n%2+'0');n/=2;}a+=(char)(n+'0');reverse(all(a));return a;
}


ll n, k, a, b, c;
string s;

int main(){
    //fast_io
    //file_io

    cin >> n >> a  >> b >> k;
    n++;
    cin >> s;

    for (int i = 0; i < k; i++){
        ll f = 1;
        if (s[i] != '+') f = -1;
        ll x = 1;
        x *= f;
        x *= power(b, i, MOD), x %= MOD;
        x *= power(a, n-1-i, MOD), x %= MOD;
        c += x, c %= MOD;
    }
    //cout << c << endl;
    ll flag = 0;
    //if (a < b) swap(a, b), flag = 1;
    c = (c + MOD) % MOD;
    ll x = power(b, k, MOD);
    ll inv = power(a, k, MOD);
    inv = power(inv, MOD-2, MOD);
    x *= inv, x = (x+MOD*100)%MOD;
    ll y = (n)/k;
    //y++;
    ll makhraj = power((x + MOD -1)% MOD, MOD-2, MOD);
    ll surat = power(x, y, MOD)-1;
    if (x == 1){
        cout << y * c % MOD << endl;
        return 0;
    }
    cout << ((surat*makhraj)%MOD)*c %MOD << endl;
    //cout << c << endl;



    return 0;
}
//! N.N