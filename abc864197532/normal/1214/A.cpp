#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int n,a,b,m=INT_MAX,tmp;
	cin >> n >> a >> b;
	b*=5;
	fop (i,0,n/a+1) {
		tmp=n-a*i;
		m=min(m,tmp%b);
	}
	cout << m << endl;
}