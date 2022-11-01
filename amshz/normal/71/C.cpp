# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

# define F first
# define S second
# define pb push_back
# define endl '\n'
# define sep ' '

const int xn = 1e5+10;
const int xm = 1e2+10;
const ll md = 1e9+7;
const int sq = 320;

int n;
bool a[xn];

int main(){
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	
	for (int i=3; i<=n; i++){
		if (n%i > 0) continue;
		int m = n/i;
		for (int j=0; j<m; j++){
			int t = 0;
			for (int k=0; k<i; k++){
				if (a[k*m+j]) t++;
			}
			if (t == i){
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	
	cout << "NO" << endl;
	
	return 0;
}