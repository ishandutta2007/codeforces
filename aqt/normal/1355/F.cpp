
// Problem : F. Guess Divisors Count
// Contest : Codeforces - Codeforces Round #643 (Div. 2)
// URL : https://codeforces.com/contest/1355/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<int> pr;
vector<int> tmp;

int query(long long n){
	cout << "? " << n << endl;
	int k;
	cin >> k;
	return k;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for(int i = 2; i<=1000; i++){
		bool b = 1;
		for(int j = 2; j<i; j++){
			if(i%j == 0){
				b = 0;
				break;
			}
		}
		if(b){
			pr.push_back(i);
		}
	}	
	while(T--){
		for(int p : pr){
			tmp.push_back(p);
		}
		long long ans = 1;
		long long smp = 1;
		long long crnt = 1;
		for(int i = 0; i<pr.size(); i++){
			if(1000000000000000000LL/pr[i] < crnt){
				smp *= query(crnt);
				crnt = 1;
				if(pr[i] >= pow(1e9/smp, 1.0/3) || (smp == 1 && pr[i] >= pow(1e9, 1.0/4))){
					break;
				}
			}
			crnt *= pr[i];
		}
		vector<int> lst;
		for(int i = 0; i<pr.size(); i++){
			if(smp%pr[i] == 0){
				lst.push_back(pr[i]);
			}
		}
		for(int i = 0; i<lst.size(); i+=2){
			long long q = 1;
			while(1000000000/lst[i] >= q){
				q *= lst[i];
			}
			while(i+1 != lst.size() && 1000000000000000000LL/lst[i+1] >= q){
				q *= lst[i+1];
			}
			long long k = query(q);
			int cnt = 0;
			while(k%lst[i] == 0){
				k /= lst[i];
				cnt++;
			}
			ans *= cnt+1;
			cnt = 0;
			while(i+1 != lst.size() && k%lst[i+1] == 0){
				k /= lst[i+1];
				cnt++;
			}
			ans *= cnt+1;
		}
		cout << "! " << max(ans+7, 2*ans) << endl;
	}
}