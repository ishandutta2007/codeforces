#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i = (m); i < (n); ++i)
#define FOP(i,m,n) for (int i = (m) - 1; i >= (n); --i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define X first
#define Y second
#define MAXN 100087

int main () {
	int n;
	lli k, t = 0;
	cin >> n >> k;
	pii time[n];
	fop (i,0,n) {
		cin >> time[i].X;
		time[i].Y = i;
	}
	sort(time, time + n);
	queue <int> in_q;
	lli ans[n];
	set <int> s1, need;
	int now = 1;
	t = time[0].X;
	in_q.push(time[0].Y);
	s1.insert(time[0].Y);
	int count = 0;
	while (true) {
		if (in_q.empty()) {
			if (need.empty()) {
				in_q.push(time[now].Y);
				s1.insert(time[now].Y);
				t = time[now].X;
				now++;
			} else {
				in_q.push(*need.begin());
				s1.insert(*need.begin());
				need.erase(need.begin());
			}
		}
		int aa = in_q.front();
		count++;
		t += k;
		ans[aa] = t;
		while (now < n and time[now].X <= t) {
			if (s1.empty() or time[now].Y < *s1.begin()) {
				in_q.push(time[now].Y);
				s1.insert(time[now].Y);
			} else {
				need.insert(time[now].Y);
			}
			now++;
		}
		if (need.size()) {
			if (s1.empty() or *s1.begin() > *need.begin()) {
				in_q.push(*need.begin());
				s1.insert(*need.begin());
				need.erase(need.begin());
			}
		}
		in_q.pop();
		s1.erase(aa);
		if (count == n) break;
	}
	fop (i,0,n) cout << ans[i] << " \n"[i == n - 1];
}