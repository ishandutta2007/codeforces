#include <bits/stdc++.h>

using namespace std;

int a, b, c, r;

void solve(){
	cin >> a >> b >> c >> r;
	if(a > b)	swap(a, b);
	int ans = b - a;
	
	a = max(a, c - r);
	b = min(b, c + r);
	
	if(a < b)
		ans -= b - a;
	printf("%d\n", ans);
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}