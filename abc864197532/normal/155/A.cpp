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
	int minn,maxx,tmp,k=0;
	cin >> minn;
	maxx=minn;
	fop (i,1,n) {
		cin >> tmp;
		if (tmp<minn) {
			k++;
			minn=tmp;
		} else if (tmp>maxx) {
			k++;
			maxx=tmp;
		}
	}
	cout << k << endl;
}