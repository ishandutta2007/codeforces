#include<bits/stdc++.h>

using namespace std;

vector< pair<int, int> > v;
int r[100000];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		
		v.push_back(make_pair(x, i));
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++) {
		r[i] = max(r[i], v[i].second);
		r[v[i].second] = max(r[v[i].second], i);
	}
	
	int R = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		R = max(r[i], R);
		
		if (R == i) {
			ans++;
			
			R = i + 1;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}