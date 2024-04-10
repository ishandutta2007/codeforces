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
	if (n%3==2) cout << 1 << ' ' << 2 << ' '<< n-3 << endl;
	else cout << 1 << ' ' << 1 << ' ' << n-2 << endl;
}