#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int LIM=2e5+7;
int pos[LIM], ile[LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a; --a;
		pos[a]=i;
	}
	rep(i, n) {
		int a;
		cin >> a; --a;
		if(i<=pos[a]) ++ile[pos[a]-i];
		else ++ile[n-i+pos[a]];
	}	
	int ans=0;
	rep(i, n) ans=max(ans, ile[i]);
	cout << ans;
}