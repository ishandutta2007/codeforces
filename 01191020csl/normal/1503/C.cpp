#include<bits/stdc++.h>
using namespace std;
struct info {
	int a, c;
}inf[100001];
bool operator<(info a, info b) {
	return a.a < b.a;
}
int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> inf[i].a >> inf[i].c, ans += inf[i].c;
	sort(inf + 1, inf + n + 1);
	for (int i = 1; i <= n; i++) inf[i].c = max(inf[i].c+inf[i].a, inf[i-1].c);
	for (int i = 1; i < n; i++)
		if (inf[i].c < inf[i+1].a) ans += inf[i+1].a-inf[i].c;
	cout << ans << endl;
}