#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int t;
	cin >> t;
	while (t--) {
		lli n,a=0,b=0,c=0,d=0,m,tmp;
		cin >> n;
		fop (i,0,n) {
			cin >> tmp;
			if (tmp%2==0) a++;
			else b++;
		}
		cin >> m;
		fop (i,0,m) {
			cin >> tmp;
			if (tmp%2==0) c++;
			else d++;
		}
		cout << a*c+b*d << endl;
	}
}