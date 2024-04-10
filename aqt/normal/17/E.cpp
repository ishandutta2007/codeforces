
// Problem : E. Palisection
// Contest : Codeforces - Codeforces Beta Round #17
// URL : https://codeforces.com/contest/17/problem/E
// Memory Limit : 128 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
char arr[4000005];
int rad[4000005];
int lft[4000005], rht[4000005];
const long long MOD = 51123987;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=2*N-1; i+=2){
		cin >> arr[i];
	}
	for(int i = 0; i<=2*N; i+=2){
		arr[i] = '#';
	}
	N = 2*N-1;
	for(int l = 0, r = 0, i = 1; i<=N; i++){
		if(i > r){
			l = r = i;
			while(r <= N && l-1 >= 0 && arr[r+1] == arr[l-1]){
				r++;
				l--;
			}
			rad[i] = r - i;
		}
		else{
			int m = r - i + l;
			if(rad[m] + i >= r){
				l = i - (r - i);
				while(r <= N && l-1 >= 0 && arr[r+1] == arr[l-1]){
					r++;
					l--;
				}
				rad[i] = r - i;
			}
			else{
				rad[i] = rad[m];
			}
		}
	}
	long long tot = 0;
	for(int i = 1; i<=N; i++){
		tot += (rad[i] + 1)/2;
		if(arr[i] == '#'){
			lft[(i - rad[i] + 1 + 1)/2]++;
			lft[(i - 1 + 1)/2+1]--;
			rht[(i + 1 + 1)/2]++;
			rht[(i + rad[i] - 1 + 1)/2 + 1]--;
		}
		else{
			lft[(i - rad[i] + 1 + 1)/2]++;
			lft[(i+1)/2+1]--;
			rht[(i+1)/2]++;
			rht[(i + rad[i] - 1 + 1)/2 + 1]--;
		}
		tot %= MOD;
	}
	tot *= tot-1;
	tot %= MOD;
	tot *= 25561994; //mod inverse for 2 for this mod
	tot %= MOD;
	N = (N+1)/2;
	for(int i = 1; i<=N; i++){
		rht[i] += rht[i-1];
		rht[i] %= MOD;
		lft[i] += lft[i-1];
		lft[i] %= MOD;
		//cout << lft[i] << " " << rht[i] << "\n";
	}
	long long cnt = 0;
	for(int i = 1; i<=N; i++){
		tot -= cnt * lft[i];
		tot %= MOD;
		tot += MOD;
		tot %= MOD;
		cnt += rht[i];
		cnt %= MOD;
	}
	cout << tot << "\n";
}