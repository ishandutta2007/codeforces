#include<bits/stdc++.h>

#define S second

using namespace std;

const int N = 5e5 + 10;


int Main(){
	
	int n, k;
	cin >> n >> k;
	vector<int> A(n), cnt(n + 1, 0);
	for(auto &x : A){
		cin >> x;
		cnt[x] ++;
	}
	int sm = 0, po = 0;
	int x = 1, y = n;
	for(int i = 1; i <= n; i++){
		sm += cnt[i];
		while(2 * (sm - cnt[po]) >= n + k){
			sm -= cnt[po];
			po++;
		}
		if(sm+sm >= n + k && (y - x) > (i - po)){
			y = i;
			x = po;
//			cerr << "?? " << y - x << '\n';
		}
	}
	vector<int> la(n + 1, 0);
	sm = 0;
	for(int i = 0; i < n; i++){
		sm += (x <= A[i] && A[i] <= y ? +1 : -1);
		if(sm > 0)
			la[sm] = i + 1;
	}
	cout << x << ' ' << y << '\n';
	if(k == 1) return cout << "1 " << n << '\n', 0;
	cout << "1 " << la[1] << '\n';
	la[k] = n;
	for(int i = 2; i <= k; i++) cout << la[i - 1] + 1 << " " << la[i] << '\n';
	return 0;
}


int main(){
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int t;
	cin >> t;
	while(t --) Main();
	return 0;
}