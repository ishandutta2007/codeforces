#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 


int main () {
	int n;
	cin >> n;
	int a=0,tmp;
	fop (i,0,n) {
		cin >> tmp;
		if (tmp%2==0) a++;
	}
	cout << min(a,n-a) << endl;
}