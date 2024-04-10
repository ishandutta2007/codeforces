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
const int xn = 3e2+10;
const int xk = 1e2+10;

bool f[xn];


int main(){
	fast_io;
	
	int n;
	cin >> n;
	string a;
	cin >> a;
	int t1 = 0, t2 = 0;
	for (int i=0; i<a.size(); i++){
		if (a[i] == 'B') t1++;
		else t2++;
	}
	char g;
	if (n%2 == 0){
		if (t1%2 == 0) g = 'B';
		else{
			cout << -1 << endl;
			return 0;
		}
	}
	else{
		if (t1%2 == 1) g = 'B';
		else g = 'W';
	}
	vector <int> ans;
	//cout << g << endl;
	for (int i=0; i<a.size(); i++){
		if (!f[i]){
			if (a[i] != g) ans.pb(i+1), f[i+1] = true;
		}
		else{
			if (a[i] == g) ans.pb(i+1), f[i+1] = true;
		}
	}
	cout << ans.size() << endl;
	for (int i=0; i<ans.size(); i++) cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}