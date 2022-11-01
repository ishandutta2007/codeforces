# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;

# define endl		 '\n'
# define sep		 ' '
# define F 			 first
# define S 			 second
# define pb			 push_back
# define fast_io 	 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b);}
ll pw(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pw(a*a, b/2)+md)%md;
	else return (a*pw(a*a, b/2)+md)%md;
}

const int xn = 2e3+10;
const int xm = 5e4+10;

int n, m;
int a[xn], b[xn], c[xn];

int tab(int a1, int a2){
	if (a2 > a1) return a2 - a1;
	return m-a1 + a2 - m;
}



int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	
	//for (int i=0; i<n; i++) c[a[i]]++, d[b[i]]++;
	
	sort(a, a+n);
	sort(b, b+n);
	
	for (int i=0; i<n; i++){
		int d = (b[i] - a[0] + m)%m;
		for (int j=0; j<n; j++) c[j] = (a[j]+d)%m;
		sort(c, c+n);
		bool fl1 = true;
		for (int j=0; j<n; j++) if (c[j] != b[j]) fl1 = false;
		if (fl1){
			cout << d << endl;
			return 0;
		}
	}
	
	return 0;
}