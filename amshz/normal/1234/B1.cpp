# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;
int a[xn];
map <int,bool> mp;

int main(){
	int n, k;
	cin >> n >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	deque <int> dq;
	for (int i=0; i<n; i++){
		if (dq.size() < k and mp[a[i]] == 0) dq.push_front(a[i]), mp[a[i]] = 1;
		else if (mp[a[i]] == 0 and dq.size() == k) mp[dq.back()] = 0, dq.pop_back(), dq.push_front(a[i]), mp[a[i]] = 1;
	}
	cout << dq.size() << endl;
	for (int i=0; i<dq.size(); i++) cout << dq[i] << ' ';
}