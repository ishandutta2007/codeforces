#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
lli MOD=1e9+7;
lli fibb[100010];


int fib(int n) {
	if (fibb[n]!=-1) return fibb[n];
	lli sum=fib(n-1)+fib(n-2);
	return fibb[n]=sum%MOD;
}


int main () {
	lli n,m;
	cin >> n >> m;
	fop (i,0,100010) fibb[i]=-1;
	fibb[0]=1;
	fibb[1]=1;
	lli sum=fib(n)+fib(m)-1;
	sum*=2;
	sum%=MOD;
	cout << sum << endl;
}