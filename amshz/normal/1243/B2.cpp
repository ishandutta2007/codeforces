# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < int, bool> pib;

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

const int xn = 5e1+10;
const int xm = 1e2+10;

map <char, int> cnt;

char c[xn], d[xn];


int main(){
	fast_io;
	
	int qq;
	cin >> qq;
	string abc = "abcdefghijklmnopqrstuvwxyz";
	while (qq--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		for (int i=0; i<26; i++) cnt[abc[i]] = 0;
		for (int i=0; i<n; i++) cnt[a[i]]++, cnt[b[i]]++, c[i] = a[i], d[i] = b[i];
		bool fl1 = true;
		for (int i=0; i<26; i++) if (cnt[abc[i]]%2 == 1) fl1 = false;
		if (!fl1){
			cout << "No" << endl;
			continue;
		}
		cout << "Yes" << endl;
		vector <pii> ans;
		for (int i=0; i<n; i++){
			if (d[i] != c[i]){
				bool fl2 = false;
				for (int j=i+1; j<n; j++){
					if (c[j] == c[i]){
						ans.pb({j+1, i+1});
						swap(c[j], d[i]);
						fl2 = true;
						break;
					}
				}
				if (fl2) continue;
				for (int j=i+1; j<n; j++){
					if (d[j] == c[i]){
						ans.pb({n, j+1});
						ans.pb({n, i+1});
						swap(d[j], c[n-1]);
						swap(c[n-1], d[i]);
						break;
					}
				}
			}
		}
			cout << ans.size() << endl;
			for (int i=0; i<ans.size(); i++) cout << ans[i].F << sep << ans[i].S << endl;
	}
	
	return 0;
}