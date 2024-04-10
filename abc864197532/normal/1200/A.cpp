#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
#define test(x) cout << #x << ' ' << x << endl;

int aa[10];

int main () {
	int n;
	cin >> n;
	char s;
	int now=0;
	fop (i,0,n) {
		cin >> s;
		if (s=='L') {
			now=0;
			while (aa[now]==1) {
				now++;
			}
			aa[now]=1;
		} else if (s=='R') {
			now=9;
			while (aa[now]==1) {
				now--;
			}
			aa[now]=1;
		} else {
			aa[s-'0']=0;
		}
	}
	fop (i,0,10) cout << aa[i];
	cout << endl;
}