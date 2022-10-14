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
int a[100000], n;

int find(int p, int from, int to) {
	if (p < 0) return 0;
	int aa = from;
	while (a[aa] & (1 << p) and aa < to) aa++;
	if (aa == to or aa == from) return find(p - 1, from, to);
	return (1 << p) + min(find(p - 1, from, aa), find(p - 1, aa, to));
}

int main () {
	cin >> n;
	fop (i,0,n) cin >> a[i];
	sort(a,a+n);
	reverse(a,a+n); 
	cout << find(29, 0, n) << endl;
}