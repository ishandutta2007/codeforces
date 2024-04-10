// https://codeforces.com/contest/1227/submission/72276776

#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef long double ld;


int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int n; scanf("%d", &n);
		int maxl = -1e9-7, minr = 1e9+7;
		for(int i = 0; i<n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			maxl = max(x, maxl), minr = min(y, minr);
		}
		printf("%d\n", max(maxl-minr, 0));
	}
	return 0;
}