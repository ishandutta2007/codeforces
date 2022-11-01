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

const int xn = 2.5e1+10;
const int xm = 1e2+10;
const ll md = 1e9+7;
const int sq = 320;

int n, m, ans;
string a[xn];

int main(){
	
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			for (int x=0; x<n; x++){
				for (int y=0; y<m; y++){
					if (x+i-1 >= n || y+j-1 >= m) continue;
					bool fl1 = true;
					for (int ii=x; ii<=x+i-1; ii++){
						for (int jj=y; jj<=y+j-1; jj++){
							if (a[ii][jj] == '1'){
								fl1 = false;
								break;
							}
						}
					}
					if (fl1){
						ans = max(ans, 2*(i+j));
						break;
					}
				}
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}