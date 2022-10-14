#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
lli MOD=1e9+7;

lli mpow(int a,int b) {
	if (b==0) return 1;
	if (b==1) return a;
	lli sum=mpow(a,b/2);
	sum=sum*sum;
	sum%=MOD;
	sum*=mpow(a,b%2);
	sum%=MOD;
	return sum;
}



int main () {
	int n,m;
	cin >> n >> m;
	lli aa=mpow(2,m)-1;
	cout << mpow(aa,n) << endl;
	
}