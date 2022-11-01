#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int p[100001];
int cnt[100001];
set<int> tmp;
int main() {
	int t = read();
	while (t--) {
		int n = read();
		for (int i = 1; i <= n; i++) p[read()] = i;
		set<int> s;
		for (int i = 0; i <= n; i++) s.insert(i), cnt[i] = 0;
		cnt[1] = n;
		tmp.clear();
		tmp.insert(1);
		bool ans = 1;
		for (int i = 1; i <= n; i++) {
			set<int>::iterator pt = s.lower_bound(p[i]);
			int num = *prev(pt);
			if (p[i] - num != *prev(tmp.end())) {
				ans = 0;
				break;
			}
			--cnt[p[i]-num];
			if (!cnt[p[i]-num]) tmp.erase(p[i] - num);
			pt = next(pt);
			if (pt != s.end()) {
				--cnt[*pt-p[i]];
				if (!cnt[*pt-p[i]]) tmp.erase(*pt - p[i]);
				if (!cnt[*pt-num]) tmp.insert(*pt - num);
				++cnt[*pt-num];
			}
			s.erase(p[i]);
		}
		if (ans) puts("Yes");
		else puts("No");
	}
}