#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> a[2][2];
char s[3];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%s%d", s, &x);
		a[s[0]-'0'][s[1]-'0'].push_back(x);
	}
	for(int i=0; i<2; i++) for(int j=0; j<2; j++)
		sort(a[i][j].begin(), a[i][j].end(), greater<int>());
	int cnt = 0; ll res = 0;
	for(int it : a[1][1]) res += it, cnt++;
	int mn = min(a[1][0].size(), a[0][1].size());
	for(int i=0; i<mn; i++) res += a[0][1][i] + a[1][0][i];
	vector<int> v;
	for(int i=mn; i<a[1][0].size(); i++) v.push_back(a[1][0][i]);
	for(int i=mn; i<a[0][1].size(); i++) v.push_back(a[0][1][i]);
	for(int it : a[0][0]) v.push_back(it);
	sort(v.begin(), v.end(), greater<int>());
	for(int i=0; i<min(cnt,(int)v.size()); i++) res += v[i];
	printf("%lld", res);
	return 0;
}