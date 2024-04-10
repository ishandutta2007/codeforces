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


int main(){
	fast_io;
	
	int qq;
	cin >> qq;
	while (qq--){
		string a, b;
		cin >> a >> b;
		vector <char> c, d;
		for (int i=0; i<a.size(); i++) c.pb(a[i]), d.pb(a[i]);
		sort(c.begin(), c.end());
		//for (int i=0; i<c.size(); i++) cout << c[i];
		//cout << endl;
		char dx = '.', g = '.';
		for (int i=0; i<c.size(); i++){
			if (a[i] != c[i]){
				dx = a[i], g = c[i];
				break;
			}
		}
		//cout << dx << sep << g << endl;
		if (dx == '.'){
			if (a < b){
				cout << a << endl;
			}
			else{
				cout << "---" << endl;
			}
			continue;
		}
		int k1, k2;
		for (int i=a.size()-1; i>=0; i--){
			if (a[i] == g){
				k1 = i;
				break;
			}
		}
		for (int i=0; i<a.size(); i++){
			if (a[i] == dx){
				k2 = i;
				break;
			}
		}
		swap(d[k1], d[k2]);
		string s = "";
		for (int i=0; i<d.size(); i++) s += d[i];
		if (s >= b){
			cout << "---" << endl;
			continue;
		}
		cout << s << endl;
	}
	
	return 0;
}