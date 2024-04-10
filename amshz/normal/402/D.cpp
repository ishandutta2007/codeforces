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

const int xn = 5e3+10;
const int xm = 5e4+10;

int n, m, a[xn], b[xn], g[xn];
unordered_map <int, bool> flag;
bool p[xm];
vector <int> pr;

int fn(int x){
	int ans = 0;
	for (int i=0; i<pr.size(); i++){
		int s = pr[i];
		int t = 0;
		while (x%s == 0){
			//cout << s << endl;
			x /= s;
			t++;
		}
		if (flag[s]) ans -= t;
		else ans += t;
		if (x == 1) break;
	}
	if (x != 1){
		if (flag[x]) ans--;
		else ans++;
	}
	return ans;
}


int main(){
	fast_io;
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++) cin >> b[i], flag[b[i]] = true;
	
	for (int i=2; i<=4e4; i++){
		if (p[i]) continue;
		pr.pb(i);
		//cout << i << endl;
		for (int j=2; j<=4e4/i; j++) p[i*j] = true;
	}
	int s = a[0];
	g[0] = a[0];
	for (int i=1; i<n; i++){
		s = gcd(s, a[i]);
		g[i] = s;
	}
	
	int t = 0;
	for (int i=0; i<n; i++) t += fn(a[i]);
	
	s = 1;
	for (int i=n-1; i>=0; i--){
		g[i] /= s;
		if (fn(g[i]) < 0){
			s *= g[i];
			t -= (i+1) * fn(g[i]);
		}
	}
	
	cout << t << endl;
	//cout << fn(961748941) << endl;
	
	return 0;
}