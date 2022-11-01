#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int h[100001], a[100001];
struct info {
	long long h;
	int id, day;
	info(long long a, int b, int c):h(a),id(b),day(c){}
};
bool operator<(const info &a, const info &b) {
	return a.day > b.day;
}
bool check(int n, int m, int k, int p, long long res) {
	priority_queue<info> pq;
	for (int i = 1; i <= n; i++) pq.push(info(res,i,res/a[i]+1));
	int x = 0;
	for (int i = 1; i <= m; i++) {
		while (pq.top().day == i) {
			if (!x) return 0;
			info tmp = pq.top();
			pq.pop();
			tmp.h += p, tmp.day = tmp.h/a[tmp.id]+1, --x;
			pq.push(tmp);
		}
		x += k;
	}
	while (pq.size()) {
		info tmp = pq.top();
		pq.pop();
		while (tmp.h - 1ll*a[tmp.id]*m < h[tmp.id]) {
			if (!x) return 0;
			tmp.h += p, --x;
		}
	}
	return 1;
}
int main() {
	int n, m, k, p;
	n = read(), m = read(), k = read(), p = read();
	long long l = 0, r = 0;
	for (int i = 1; i <= n; i++) h[i] = read(), a[i] = read(), r = max(r, h[i]+1ll*a[i]*m);
	while (l < r) {
		long long mid = (l + r) / 2;
		if (check(n, m, k, p, mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}