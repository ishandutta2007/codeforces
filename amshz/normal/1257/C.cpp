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

const int xn = 2e5+10;
const int xm = 1e2+10;

int a[xn];


int main(){
	fast_io;
	//cout << pow(3, 14);
	int qq;
	cin >> qq;
	while (qq--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		
		map <int, int> cnt;
		int dx = -1;
		int val;
		for (int i=0; i<n; i++){
			cnt[a[i]]++;
			if (cnt[a[i]] == 2){
				dx = i;
				val = a[i];
				break;
			}
		}
		if (dx == -1){
			cout << -1 << endl;
			continue;
		}
		int mx = dx+1;
		//cout << n << sep << dx << sep << "wligcwr" << endl;
		for (int i=1; i<n; i++){
			cnt[a[i-1]]--;
			while (true){
				if (cnt[val] == 2){
					mx = min(mx, dx-i+1);
					break;
				}
				dx++;
				if (dx == n){
					dx = -1;
					break;
				}
				cnt[a[dx]]++;
				if (cnt[a[dx]] == 2){
					val = a[dx];
					mx = min(mx, dx-i+1);
					break;
				}
			}
			//cout << n << sep;
			//cout << dx << sep;
			//cout << endl;
			if (dx == -1) break;
		}
		//cout << "ans : ";
		cout << mx << endl;
	}
	
	return 0;
}