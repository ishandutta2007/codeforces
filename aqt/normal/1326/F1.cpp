
// Problem : F1. Wise Men (Easy Version)
// Contest : Codeforces Global Round 7
// URL : https://codeforces.com/contest/1326/problem/F1
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int adj[20], cadj[20];
long long dp[20][1<<18];
long long ans[1<<18];
int who[1<<18];
vector<int> msk[20];
bool done[1<<18];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i<N; i++){
		for(int j =0; j<N; j++){
			char c;
			cin >> c;
			int k = c-'0';
			adj[i] ^= k*(1<<(j));
			k ^= 1;
			cadj[i] ^= k*(1<<(j));
		}
		//cout << adj[i] << " " << cadj[i] << "\n";
	}
	for(int m = 0; m<1<<N; m++){
		msk[__builtin_popcount(m)].emplace_back(m);
	}
	int slst = -1;
	for(int m = 1; m<1<<N; m<<=1){
		dp[__builtin_ctz(m)][m] = 1; 
		who[m] = __builtin_ctz(m);
	}
	for(int ss = 0; ss<1<<(N-1); ss++){
		if(done[ss]){
			continue;
		}
		int s = 0;
		for(int t = 0; t<N-1; t++){
			if((ss>>t)&1){
				s |= (1<<(N-2-t));
			}
		}
		int d = 0;
		if(slst != -1){
			for(int t = 0; t<N-1; t++){
				if(((1<<t)&(slst)) != ((1<<t)&s)){
					break;
				}
				d++;
			}
		}		
		for(int k = d+2; k<=N; k++){
			for(const int m : msk[k]){
				for(int tmp = m; tmp; tmp ^= tmp&-tmp){
					dp[who[tmp&-tmp]][m] = 0;
				}				
			}
		}
		for(int k = d+1; k<=N; k++){
			const bool forw = (s>>(k-1))&1;			
			for(const int m : msk[k]){
				for(int tmp = m; tmp; tmp ^= tmp&-tmp){
					const int k = who[tmp&-tmp];
					if(dp[k][m]){
						int a = forw ? adj[k] : cadj[k];
						for(a ^= (a&m); a; a ^= a&-a){
							dp[who[a&-a]][m|(a&-a)] += dp[k][m];
						}
					}
				}
			}		
		}
		for(int n = 0; n<N; n++){
			ans[s] += dp[n][(1<<N)-1];
		}
		ans[ss] = ans[s];
		done[ss] = done[s] = 1;
		slst = s;
	}
	for(int m = 0; m<1<<(N-1); m++){
		cout << ans[m] << " ";
	}
}