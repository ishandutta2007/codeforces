#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define maxn 100100

int n;
long long x[maxn], temp[maxn];

void go(int k, int t)
{
	priority_queue<long long, vector<long long>, greater<long long> > q;
	for(int i = 0; i < min(n,k); i++) q.push(0);
	for(int i = 0; i < n; i++)
	{
		long long T = q.top();
		T = max(T, x[i]);
		q.pop();
		x[i] = T+t;
		q.push(T+t);
	}
}

int main()
{
	int k1,k2,k3,t1,t2,t3;
	cin >> k1 >> k2 >> k3 >> t1 >> t2 >> t3 >> n;
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < n; i++) temp[i] = x[i];
	go(k1,t1);
	go(k2,t2);
	go(k3,t3);
	long long res = 0;
	for(int i = 0; i < n; i++) res = max(res, x[i] - temp[i]);
	cout << res << endl;
}