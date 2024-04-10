/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	pair <int, int> ar [n];
	for(int i = 0; i < n; i++){
		cin >> ar[i].first;
		ar[i].second = i;;
	}
	sort(ar, ar + n);
	int ans[n], ma = 0;
	for(int i = 0; i < n; i++){
		int m = max(ma, ar[i].first);
		ma = m + 1;
		ans[ar[i].second] = m;
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}
}