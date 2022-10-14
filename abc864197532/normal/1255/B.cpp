#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair <int,int>
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n,m,all=0,tmp,t1= INT_MAX,t2=INT_MAX,aa,bb;
		cin >> n >> m;
		if (n > m or n == 2) {
			cout << -1 << endl;
			fop (i,0,n) cin >> tmp;
		} else {
			fop (i,0,n) {
				cin >> tmp;
				all += tmp;
				if (t1 > tmp) {
					t2 = t1;
					t1 = tmp;
					bb = aa;
					aa = i;
				} else if (t2 > tmp) {
					t2 = tmp;
					bb = i;
				}
			}
			cout << all*2+(t1+t2)*(m-n) << endl;
			fop (i,1,n+1) {
				cout << i << ' ' << (i%n)+1 << endl;
			}
			fop (i,0,m-n) {
				cout << aa+1 << ' ' << bb+1 << endl;
            }
        }
    }
}