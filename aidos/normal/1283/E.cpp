#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int mod = (int)1e9 + 7;
const int inf = (1<<30);
int n;
int a[200100];
vector< pair<int, int> > ans;
int x[200200];
int y[200200];
int d[200200];
int c[200200];
int main () {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[a[i]+1]++;
	}
	n+=10;
	for(int i = 1; i <= n; i++) {
		c[i] = d[i];
	}
	int last = 0;
	for(int i = 1; i <= n; i++) {
		if(c[i-1]) x[i] = 1;
		else if(c[i]) {
			x[i] = 1;
			c[i]--;
		}else if(c[i+1]) {
			c[i+1]--;
			x[i] = 1;
		}
	}
	int ans1 = 0;
	for(int i = 1; i <= n; i++)
		ans1 += x[i];
	for(int i = 1; i <= n; i++) {
		c[i] = d[i];
		x[i] = 0;
	}
	for(int i = 1; i <= n+1; i++) {
		if(c[i-1]) {
			x[i] = 1;
			c[i-1] = 0;
			c[i] = 0;
			c[i+1] = 0;
		}
	}
	int ans2 = 0;
	for(int i = 1; i <= n; i++){
		ans2 += ((x[i]>0)|| (c[i] > 0));
	}
	cout << ans2 << " " << ans1 << "\n";
 	return 0;
}