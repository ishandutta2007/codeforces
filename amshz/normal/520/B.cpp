# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;

# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

const ll md = 1e9+7;

string bin(ll n){
	string ans = "";
	while (n > 0){
		if (n%2 == 0) ans = '0'+ans;
		else ans = '1'+ans;
		n /= 2;
	}
	return ans;
}
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 1e5+10;
const int xm = 1e2+10;

int ans[xn];
bool mark[xn];

int main(){
	fast_io;
	
	int n, m;
	cin >> n >> m;
	
	for (int i=0; i<=1e5; i++) ans[i] = 1e9;
	queue <int> q;
	q.push(n);
	ans[n] = 0, mark[n] = true;
	while (q.size()){
		int v = q.front();
		mark[v] = true;
		q.pop();
		//cout << v << endl;
		if (2*v < 1e5 and !mark[2*v]) q.push(2*v), ans[2*v] = min(ans[2*v], ans[v]+1);
		if (v > 0 and !mark[v-1]) q.push(v-1), ans[v-1] = min(ans[v-1], ans[v]+1);
	}
	//for (int i=1; i<=50; i++) cout << i << " : " << ans[i] << endl;
	
	cout << ans[m] << endl;
	return 0;
}