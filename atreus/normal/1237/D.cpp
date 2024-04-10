#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const int maxn = 3e5 + 10;

int a[maxn], ans[maxn], go[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mn = *min_element(a, a + n), mx = *max_element(a, a + n);
	if (2 * mn >= mx){
		for (int i = 0; i < n; i++)
			cout << -1 << " ";
		cout << endl;
		return 0;
	}
	for (int i = n; i < 2*n; i++)
		a[i] = a[i-n];
	for (int i = 2 * n; i < 3 * n; i++)
		a[i] = a[i-n];
	deque<int> deq;
	memset(go, -1, sizeof go);
	for (int i = 0; i < 3 * n; i++){
		while (!deq.empty() and a[deq.back()] > 2 * a[i]){
			ans[deq.back()] = i - deq.back();
			deq.pop_back();
		}
		while (!deq.empty() and a[deq.front()] < a[i]){
			go[deq.front()] = i;
			ans[deq.front()] = i - deq.front();
			deq.pop_front();
		}
		deq.push_front(i);
	}
	for (int i = 3 * n - 1; i >= 0; i--)
		if (go[i] != -1)
			ans[i] += ans[go[i]];
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}