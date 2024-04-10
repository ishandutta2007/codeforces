# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e18;
const int xn = 1e5 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
//ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
//ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll qq, n, a, b, m, x[xn];

int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		cin >> a >> b >> m;
		memset(x, 0, sizeof x);
        ll k = 0 , sum;
        x[0] = a;
        sum = a;
        while(sum + 1 <= b){
            x[++k] = sum + 1;
            sum += x[k];
        }
        for(ll i = 1 ; i <= k ; i++){
            ll factor = (i == k ? 1 : power(2 , k - i - 1));
            ll t = min(m - 1 , (b - x[k]) / factor);
            for(ll j = i ; j <= k ; j++){
                ll f = (i == j ? 1 : power(2 , j - i - 1));
                x[j] += f * t;
            }
        }
 
        if(x[k] != b){
            cout << -1 << endl;
            continue;
        }
        cout << k + 1 << sep;
        for(ll i = 0 ; i <= k ; i++)    cout << x[i] << sep;
        cout << endl;
	}
		
	return 0;
}