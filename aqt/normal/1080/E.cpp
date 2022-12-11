
// Problem : E. Sonya and Matrix Beauty
// Contest : Codeforces - Codeforces Round #524 (Div. 2)
// URL : https://codeforces.com/contest/1080/problem/E
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
char arr[255][255];
const long long MOD = 1e9+7;
const long long sd = 301;
long long hsh[505];
bool good[505];
int rad[505];
long long pows[505];
int msk[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	pows[0] = 1;
	for(int i = 1; i<=500; i++){
		pows[i] = pows[i-1] * sd % MOD;
	}
	for(int i = 1; i<=N; i++){
		for(int j =1; j<=M; j++){
			cin >> arr[i][j];
		}
	}
	long long ans = 0;
	for(int c1 = 1; c1<=M; c1++){
		for(int c = 0; c<26; c++){
			for(int n = 1; n<=N; n++){
				msk[n] = 0;
				hsh[2*n-1] = 0;
			}
		}
		fill(msk, msk+2*N, 0);
		fill(hsh, hsh+2*N, 0);
		for(int c2 = c1; c2<=M; c2++){
			fill(good+1, good+2*N, 1);
			for(int r = 1; r<=N; r++){
				msk[r] ^= (1<<(arr[r][c2]-'a')); 
				hsh[2*r-1] += pows[arr[r][c2]-'a'];
				hsh[2*r-1] %= MOD;
				good[2*r-1] = (__builtin_popcount(msk[r]) <= 1);
			}
			int c = 0;
			int lst = 0;
			for(int i = 1; i<2*N; i++){
				if(!good[i]){
					continue;
				}
				if(i > lst){
					rad[i] = 0;
					while(rad[i]+i < 2*N-1 && i-rad[i] > 1 && hsh[i+rad[i]+1] == hsh[i-rad[i]-1] && good[i+rad[i]+1] && good[i-rad[i]-1]){
						rad[i]++;
					}
					lst = i+rad[i];
					c = i;
				}
				else if(rad[2*c-i] + i >= lst){
					rad[i] = lst - i;
					while(rad[i]+i < 2*N-1 && i-rad[i] > 1 && hsh[i+rad[i]+1] == hsh[i-rad[i]-1] && good[i+rad[i]+1] && good[i-rad[i]-1]){
						rad[i]++;
					}
					lst = i+rad[i];
					c = i;
				}
				else{
					rad[i] = rad[2*c-i];
				}
			}
			for(int i= 1; i<2*N; i++){
				if(!good[i]){
					continue;
				}
				if(i%2 == 1){
					ans += (rad[i] + 2)/2;	
				}
				else{
					ans += (rad[i] + 1)/2;
				}
			}
			//cout << c1 << " " << c2 << " " << ans << "\n";
			//cout << hsh[1] << " " << hsh[2] << " " << hsh[3] << "\n";
		}
	}
	cout << ans;
}