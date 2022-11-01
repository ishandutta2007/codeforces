#include<bits/stdc++.h>
using namespace std;
struct node {
	int l, r, num;
};
node nd[500001];
int tot;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int last = -1;
	long long ans = 0, sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (i == 0 || s[i-1] == '1') {
				while (last < i) ++tot, nd[tot].l = nd[tot].r = ++last, sum += nd[tot].num = i-last;
			}
			else nd[tot].r = i;
			last = i;
		}
		else {
			while (tot >= 2 && nd[tot-1].num <= i-last) sum += 1ll*(nd[tot].r-nd[tot].l+1)*(i-last-nd[tot].num), --tot, nd[tot].r = last;
			if (tot) sum += 1ll*(nd[tot].r-nd[tot].l+1)*(i-last-nd[tot].num), nd[tot].num = i-last;
		}
		ans += sum+1ll*(i-last)*(i-last+1)/2;
	}
	cout << ans << endl;
}