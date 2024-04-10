
// Problem : B. Motarack's Birthday
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/B
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		vector<int> v;
		int N;
		cin >> N;
		int lst;
		cin >> lst;
		int mx = 0;
		for(int i = 2; i<=N; i++){
			int n;
			cin >> n;
			if(lst == -1 && n != -1){
				v.push_back(n);
			}
			else if(lst != -1 && n == -1){
				v.push_back(lst);
			}
			else{
				mx = max(mx, abs(n-lst));
			}
			lst = n;
		}
		if(v.empty()){
			cout << mx << " " << 0 << "\n";
			continue;
		}
		sort(v.begin(), v.end());
		int k = (v[0] + v.back())/2;
		mx = max(v.back()-k, mx);
		cout << mx << " " << k << "\n";
	}
}