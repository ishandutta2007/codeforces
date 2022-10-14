#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int n;
	cin >> n;
	int x[n],v[n];
	fop (i,0,n) cin >> x[i];
	sort(x,x+n);
	fop (i,0,n) v[i]=0;
	int ans=0;
	fop (i,0,n) {
		if (v[i]==0) {
			v[i]=1;
			ans++;
			fop (j,i+1,n) {
				if (x[j]%x[i]==0) v[j]=1;
			}
		}
	}
	cout << ans << endl;
}