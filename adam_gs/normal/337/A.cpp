#include<bits/stdc++.h>
using namespace std;
#define rep(a,b) for(int a = 0; a < (b); ++a)
int main() {
	int n, m;
	cin >> n >> m;
	int T[m];
	rep(i, m) cin >> T[i];
	sort(T, T+m);
	int mi=100000007;
	rep(i, m-n+1) mi=min(mi, T[n+i-1]-T[i]);
	cout << mi;
}