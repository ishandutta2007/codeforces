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

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 5e2+10;
const int xk = 1e2+10;

string a[xn], ans[xn];

int fn1(char f){
	return f-'0';
}


int main(){
	fast_io;
	//cout << fn1('1');
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
		int s = 0, t = 0;
		bool fl1 = false;
		for (int j=0; j<a[i].size(); j++){
			if (fn1(a[i][j]) == 0) fl1 = true;
			if (fn1(a[i][j])%2 == 0) t++;
			s += fn1(a[i][j]);
		}
		if (fl1 && t > 1 && s%3 == 0){
			ans[i] = "red";
		}
		else{
			ans[i] = "cyan";
		}
	}
	for (int i=0; i<n; i++) cout << ans[i] << endl;
	
	return 0;
}