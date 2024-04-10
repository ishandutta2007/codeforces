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
#define X first
#define Y second
const int N = 1000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
	    int n;
	    cin >> n;
	    int tmp;
	    int x = -1, y = -1, k = -1;
	    fop (i,0,n) {
	        cin >> tmp;
	        if (tmp & 1) {
	            if (x == -1) {
	                x = i;
	            } else if (y == -1) {
	                y = i;
	            }
	        } else {
	            k = i;
	        }
	    }
	    if (k != -1) cout << 1 << endl << k + 1 << endl;
	    else if (y != -1) cout << 2 << endl << x + 1 << ' ' << y + 1 << endl;
	    else cout << -1 << endl;
	}
}