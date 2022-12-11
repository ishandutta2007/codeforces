
// Problem : A. Phoenix and Balance
// Contest : Codeforces - Codeforces Round #638 (Div. 2)
// URL : https://codeforces.com/contest/1348/problem/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		/*
		deque<int> dq;
		for(int i = 1; i<=N; i++){
			dq.push_back(i);
		}
		long long v = 0;
		for(int i = 0; i<N/2; i++){
			if(i%2 == 1 && dq.size() == 2){
				if(abs(v - (dq.front()<<1) + (dq.back()<<1)) < abs(v + (dq.front()<<1) - (dq.back()<<1))){
					v -= dq.front()<<1;
					v += dq.back()<<1;
				}
				else{
					v += dq.front()<<1;
					v -= dq.back()<<1;
				}
				break;
			}
			else if(i%4 == 0 || i%4 == 3){
				v += 1<<dq.front();
				v += 1<<dq.back();
				dq.pop_front();
				dq.pop_back();
			}
			else{
				v -= 1<<dq.front();
				v -= 1<<dq.back();
				dq.pop_front();
				dq.pop_back();				
			}
		}
		cout << abs(v) << "\n";
		*/
		long long v = 1<<N;
		for(int i = 1; i<N/2; i++){
			v += 1<<i;
		}
		for(int i = N/2; i<N; i++){
			v -= 1<<i;
		}
		cout << v << "\n";
	}
}