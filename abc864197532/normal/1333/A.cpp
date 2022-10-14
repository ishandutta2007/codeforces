#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
	    int n, m;
	    cin >> n >> m;
	    if (n & 1 and m & 1) {
    	    fop (i,0,n) {
    	        fop (j,0,m) {
    	            cout << ((i + j) % 2 == 0 ? 'B' : 'W');
    	        }
    	        cout <<'\n';
    	    }
	    } else {
            fop (i,0,n) {
                fop (j,0,m) {
                    if (i + j != 0 and (i + j) % 2 == 0) cout << 'W';
                    else cout << 'B';
                }
                cout << '\n';
            }
	    }
	}
}