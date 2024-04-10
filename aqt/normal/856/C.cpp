#include <bits/stdc++.h>

using namespace std;

int T, N;
int aqtdp[2005][2005][11];
int dp[2005][2005][11];
long long sum[2005];
const long long MOD = 998244353;
int arr[2005];
vector<int> even, odd;

long long add(long long a, long long b){
	return (a + b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

inline int gd(int n){
    int cnt = 0;
    while(n){
        cnt++;
        n/=10;
    }
    return cnt;
}
 
inline int gs(int n){
    /*
    int sum = 0;
    while(n){
        sum-=n%10;
        n/=10;
    }
    if(gd(n)%2) sum = -sum;
    return sum;
    */
    return n%11;
}

long long solve(int NO, int NE, vector<long long> basecase, vector<int> v){
	int initoddspots = (NO+1)/2;
	int initevenspots = NO + 1 - initoddspots;
	for(int i = 0; i<=NE; i++){
		for(int e = 0; e<2003; e++){
			for(int m = 0; m<11; m++){
				aqtdp[i][e][m] = 0;
			}
		}
	}
	for(int k = 0; k<11; k++){
		//cout << k << " " << basecase[k] << "\n";
		aqtdp[0][initevenspots][k] = basecase[k];
	}
	//cout << "\n";
	for(int i = 0; i<NE; i++){
		int ev = v[i] % 11;
		int ov = v[i] * 10 % 11;
		for(int e = 0; e<2003; e++){
			for(int m = 0; m<11; m++){
				aqtdp[i+1][e+1][(m + ev)%11] = add(aqtdp[i+1][e+1][(m + ev)%11], mult(aqtdp[i][e][m], e));
				aqtdp[i+1][e][(m+ov)%11] = add(aqtdp[i+1][e][(m+ov)%11], mult(aqtdp[i][e][m], NO + i + 1 - e));
			}
		}
	}
	long long ans = 0;
	for(int e = 0; e<2003; e++){
		ans = add(ans, aqtdp[NE][e][0]);
	}
	return ans;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
        cin >> N;
        odd.clear();
        even.clear();
        for(int i=1; i<=N; i++){
            cin >> arr[i];
            if(gd(arr[i])%2) odd.push_back(gs(arr[i])%11);
            else even.push_back(gs(arr[i])%11);
        }
        int odd_pos = (odd.size()+1)/2;
        int even_pos = odd.size()-odd_pos;
        for(int i=0; i<=odd.size(); i++)
            for(int k=0; k<=odd.size(); k++)
                memset(dp[i][k],0,sizeof dp[i][k]);
        dp[0][0][0] = 1;
		for(int i=0; i<odd.size(); i++){
            for(int k=0; k<=even_pos; k++){
                for(int mod=0; mod<11; mod++){
                    if(dp[i][k][mod] == 0) continue;
                    int rem_even = even_pos-k;
                    int rem_odd = odd_pos-(i-k);
                    if(rem_odd){
                        int new_mod = (mod+odd[i]+11)%11;
                        dp[i+1][k][new_mod] = (int) ((dp[i+1][k][new_mod]+1LL*dp[i][k][mod]*rem_odd)%MOD);
                    }
                    if(rem_even){
                        int new_mod = (mod-odd[i]+11)%11;
                        dp[i+1][k+1][new_mod] = (int) ((dp[i+1][k+1][new_mod]+1LL*dp[i][k][mod]*rem_even)%MOD);
                    }
                }
            }
        }
        for(int i=0; i<11; i++)
            sum[i] = dp[odd.size()][even_pos][i];
        vector<long long> base;
        for(int i = 0; i<11; i++){
        	base.push_back(sum[i]);
        }
        cout << solve(odd.size(), even.size(), base, even) << "\n";		
	}
}