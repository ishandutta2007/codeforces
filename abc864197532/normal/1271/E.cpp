#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
 
int find (lli k) {
	int a = 0;
	while (k > 1) {
		k >>= 1;
		a++;
	}
	return a;
}
 
 
int main () {
	lli n,k;
	cin >> n >> k;
	lli aa = n - k, sum;
	if (__builtin_popcountll(k+1) == 1) {
		sum = aa / (k + 1);
		sum *= 2;
		if (aa % (k + 1)) sum += 2;
		else sum++;
	} else {
		aa--;
		if (aa < 0) {
			sum = 1;
		} else {
			sum = aa / (1ll << find(k));
			sum++;
			sum *= 2;
		}
	}
	cout << sum << endl;
}