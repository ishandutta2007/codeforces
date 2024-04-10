
// Problem : D. Alice, Bob and Candies
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		deque<int> dq;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			dq.push_back(n);
		}
		long long lst = 0, tot = 0, a = 0, b = 0;
		int n = 0;
		while(dq.size()){
			if(n%2 == 0){
				tot += dq.front();
				a += dq.front();
				dq.pop_front();
				if(tot > lst){
					n++;
					//a += tot;
					lst = tot;
					tot = 0;
				}
			}
			else{
				tot += dq.back();
				b += dq.back();
				dq.pop_back();
				if(tot > lst){
					n++;
					//b += tot;
					lst = tot;
					tot = 0;
				}
			}
		}
		if(tot){
			n++;
		}
		cout << n << " " << a << " " << b << "\n";
	}
}