#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(int a = 0; a < (b); ++a)
int main() {
	int n;
	cin >> n;
	int t[n];
	rep(i, n) cin >> t[i];
	sort(t, t+n);
	rep(i, n) cout << t[i] << " ";
}