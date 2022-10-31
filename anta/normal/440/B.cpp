#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int a[50000];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	long long sum = accumulate(a, a + n, 0LL);
	int avg = (int)(sum / n);
	queue<pair<int,int> > q;
	long long ans = 0;
	for(int i = 0; i < n; i ++) {
		if(a[i] > avg)
			q.push(make_pair(a[i] - avg, i));
	}
	for(int i = 0; i < n; i ++) {
		if(a[i] < avg) {
			int diff = avg - a[i];
			while(diff > 0) {
				pair<int,int> p = q.front();
				int x = min(p.first, diff);
				diff -= x;
				ans += (long long)x * abs(p.second - i);
				if((q.front().first -= x) == 0)
					q.pop();
			}
		}
	}
	cout << ans << endl;
	return 0;
}