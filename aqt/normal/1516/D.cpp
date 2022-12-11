
// Problem : D. Cut
// Contest : Codeforces - Codeforces Round #717 (Div. 2)
// URL : https://codeforces.com/contest/1516/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int arr[100005];
int tbl[20][100005];
int lft[20][100005];
int cnt[100005];
int sieve[100005];

struct node{
	int l, r, g;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 2; i<=100000; i++){
		if(!sieve[i]){
			for(int j = i; j<=100000; j+=i){
				sieve[j] = i;
			}
		}
	}
	cin >> N >> Q;
	//N = 100000;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		//arr[i] = rand()%100000+1;
		tbl[0][i] = arr[i];
	}
	//cout<< arr[1] << " " << arr[2] << endl;
	for(int r = 1, l = 1; r<=N; r++){
		int t = arr[r];
		while(t > 1){
			int i = sieve[t];
			while(cnt[i]){
				int tmp = arr[l];
				while(tmp > 1){
					int j = sieve[tmp];
					cnt[j]--;
					do{
						tmp /= j;
					}
					while(tmp%j == 0);
				}
				l++;
			}
			do{
				t /= i;	
			}
			while(t%i == 0);
			cnt[i]++;
		}
		/*
		for(int i = 2; i*i <= t; i++){
			if(t%i == 0){
				
			}
		}
		if(t > 1){
			while(cnt[t]){
				int tmp = arr[l];
				for(int j = 2; j*j <= tmp; j++){
					if(tmp%j == 0){
						cnt[j]--;
						do{
							tmp /= j;
						}
						while(t%j == 0);
					}
				}
				if(tmp > 1){
					cnt[tmp]--;
				}
				l++;
			}
			cnt[t]++;
		}
		*/
		//cout << l << " " << r << "\n";
		tbl[0][r] = l-1;
	}
	for(int l = 1; l<20; l++){
		for(int i = 1; i<=N; i++){
			tbl[l][i] = tbl[l-1][tbl[l-1][i]];
		}
	}
	//Q = 100000;
	while(Q--){
		int l, r;
		cin >> l >> r;
		
		int ans = 0;
		for(int d = 19; d>=0; d--){
			if(tbl[d][r] >= l){
				r = tbl[d][r];
				ans += (1<<d);
			}
		}
		cout << ans+1 << "\n";
	}
}