#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 

int main () {
	int b,g,n;
	cin >> b >> g >> n;
	int m=n+1;
	m-=max(n-b,0);
	m-=max(n-g,0);
	cout << m << endl;
}