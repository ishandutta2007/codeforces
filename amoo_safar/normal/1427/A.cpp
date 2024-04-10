// I'll Crush you !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N]; 
void Main(){
	ll n;
	cin >> n;
	ll s = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) s += a[i];
	if(s == 0){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	sort(a, a + n);
	if(s > 0)
		reverse(a, a + n);
	for(int i = 0; i < n; i++)
		 cout << a[i] << ' ';
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}