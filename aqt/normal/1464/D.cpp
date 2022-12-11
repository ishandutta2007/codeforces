
// Problem : D. The Thorny Path
// Contest : Codeforces - Codeforces Round #692 (Div. 1, based on Technocup 2021 Elimination Round 3)
// URL : https://codeforces.com/contest/1464/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N, O;
int nxt[1000005];
bool vis[1000005];
int fre[3];
const long long MOD = 1e9+7;

int calc(){
	int mn = min(fre[1], fre[2]);
	//cout << " " << fre[1] << " " << fre[2] << "\n";
	return mn + (fre[1]-mn)/3*2 + (fre[2]-mn);
}

int solve(bool has2){
	int ans = INT_MAX;
	if(O >= 2){
		fre[1] -= 2;
		ans = calc() + 1;
		fre[1] += 2;
	}
	if(O < fre[1]){
		fre[1]--;
		fre[2]++;
		ans = min(ans, calc());
		fre[1]++;
		fre[2]--;
	}
	if(fre[2]){
		fre[2]--;
		fre[0]++;
		ans = min(ans, calc());
		fre[2]++;
		fre[0]--;
	}
	if(has2){
		fre[2]--;
		ans = min(ans, calc());
		fre[2]++;
	}
	if(fre[0]){
		fre[0]--;
		fre[1]++;
		ans = min(ans, calc() + 1);
		fre[0]++;
		fre[1]--;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		fre[0] = fre[1] = fre[2] = 0;
		fill(vis+1, vis+1+N, 0);
		cin >> N;
		int ans = INT_MAX;
		for(int i = 1; i<=N; i++){
			cin >> nxt[i];
		}
		vector<int> sz;
		O = 0;
		int C = 0;
		for(int n = 1; n<=N; n++){
			if(!vis[n]){
				int len = 0;
				while(!vis[n]){
					vis[n] = 1;
					n =nxt[n];
					len++;
				}
				sz.push_back(len);
				fre[len%3]++;
				if(len%3 == 0){
					C += len/3-1;
				}
				else{
					C += len/3;
				}
				O += (len == 1);
			}
		}
		long long val;
		//cout << fre[0] << " " << fre[1] << " " << fre[2] << "\n";
		if(N%3 == 0){
			val = 1;
			for(int i = 0; i<N/3; i++){
				val *= 3;
				val %= MOD;
			}
			ans = calc();
		}
		else if(N == 1){
			cout << "1 0\n";
			continue;
		}
		else if(N%3 == 2){
			val = 2;
			for(int i = 0; i<N/3; i++){
				val *= 3;
				val %= MOD;
			}			
			ans = solve(find(sz.begin(), sz.end(), 2) != sz.end());
		}
		else{
			val = 4;
			for(int i = 0; i<N/3-1; i++){
				val *= 3;
				val %= MOD;
			}	
			if(find(sz.begin(), sz.end(), 3) != sz.end() && O){
				fre[0]--;
				O--;
				fre[1]--;
				ans = min(ans, calc()+1);
				fre[0]++;
				O++;
				fre[1]++;
			}
			for(int s : sz){
				if(s >= 4){
					fre[s%3]--;
					fre[(s%3+2)%3]++;
					ans = min(ans, calc() - (s%3 == 1));
					fre[s%3]++;
					fre[(s%3+2)%3]--;
				}
			}
			bool spcase = 0;
			bool has2 = (find(sz.begin(), sz.end(), 2) != sz.end());
			for(auto ptr = sz.begin(); ptr != sz.end(); ptr++){
				int s = *ptr;
				if(s == 2 && !spcase){
					fre[2]--;
					fre[0]++;
					spcase = 1;
					ans = min(ans, solve(find(ptr+1, sz.end(), 2) != sz.end()));
					fre[2]++;
					fre[0]--;
				}
				else if(s > 2){
					fre[s%3]--;
					fre[(s%3+1)%3]++;
					ans = min(ans, solve(has2));
					fre[s%3]++;
					fre[(s%3+1)%3]--;
				}
			}
			if(O >= 2){
				O -= 2;
				fre[1] -= 2;
				ans = min(ans, solve(has2)+1);
				fre[1] += 2;
				O += 2;
			}
		}
		cout << val << " " << ans+C << "\n";
	}
}