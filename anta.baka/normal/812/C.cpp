/*















*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, S, k;
pair<int,int> a[100000];

int cost(int p) {
	k = p;
	if(!k) return 0;
	sort(a, a + n, [](pair<int,int> A, pair<int,int> b){ return A.first + k * A.second < b.first + k * b.second; });
	int sm = 0;
	for(int i = 0; i < k; i++) sm += a[i].first + k * a[i].second;
	return sm;
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> S;
	for(int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
	int bl = 0, br = n;
	while(bl < br) {
		int bm = (bl + br) / 2;
		if(bl == bm) bm++;
		if(cost(bm) <= S) bl = bm;
		else br = bm - 1; 
	}
	cout << bl << ' ' << cost(bl);
}