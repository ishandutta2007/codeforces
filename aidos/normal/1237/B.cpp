#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
int n;
int a[100100];
int b[100100];
int p[100100];
int main () {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
		b[i] = p[b[i]];
	}
	int mx = 1e9;
	int ans = 0;
	for(int i = n-1; i >= 0; i--) {
		if(mx < b[i]) ans++;
		mx = min(b[i], mx);
	}
	cout << ans << "\n";

	
 	return 0;
}