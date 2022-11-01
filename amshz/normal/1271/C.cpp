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
const int xn = 2e5+10;
const int xk = 1e2+10;

int n, x, y, r, t;
pii a[xn];
int s[4];


int main(){
	fast_io;
	
	cin >> n >> x >> y;
	for (int i=0; i<n; i++) cin >> a[i].F >> a[i].S;
	for (int i=0; i<n; i++){
		if (a[i].F < x){
			s[0]++;
		}
		if (a[i].F > x) s[1]++;
		//if (a[i].F == x) s[0]++, s[1]++;
	}
	for (int i=0; i<n; i++){
		if (a[i].S < y) s[2]++;
		if (a[i].S > y) s[3]++;
	}
	int ans = 0;
	int mx = max(max(s[0], s[1]), max(s[2], s[3]));
	r = x, t = y;
	if (mx == s[0]) r = x-1;
	else if (mx == s[1]) r = x+1;
	else if (mx == s[2]) t = y-1;
	else t = y+1;
	//int ans = 0;
	cout << mx << endl;
	cout << r << sep << t << endl;
	
	return 0;
}