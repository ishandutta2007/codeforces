#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	while (c != '-' && !isdigit(c)) c = getchar();
	int neg = 0;
	if (c == '-') neg = 1, c = getchar();
	int num = 0;
	while (isdigit(c)) {
		num = num * 10 + c - '0';
		c = getchar();
	}
	return neg ? -num : num;
}
int h[300001], b[300001];
long long f[300001];
struct info {
	int m;
	long long res;
};
int main() {
	int n = read();
	for (int i = 1; i <= n; i++) h[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	vector<info> v;
	priority_queue<long long> pq1, pq2;
	for (int i = 1; i <= n; i++) {
		info tmp;
		tmp.m = i, tmp.res = f[i-1];
		while (v.size() && h[(v.end()-1)->m] >= h[i]) {
			tmp.res = max(tmp.res, (v.end()-1)->res);
			pq2.push((v.end()-1)->res+b[(v.end()-1)->m]), v.pop_back();
		}
		pq1.push(tmp.res + b[i]), v.push_back(tmp);
		while (pq2.size() && pq1.top() == pq2.top())
			pq1.pop(), pq2.pop();
		f[i] = pq1.top();
	}
	cout << f[n] << endl;
}