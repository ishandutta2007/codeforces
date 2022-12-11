
// Problem : C. Prairie Partition
// Contest : Codeforces - Codeforces Round #412 (rated, Div. 1, based on VK Cup 2017 Round 3)
// URL : https://codeforces.com/contest/806/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
int p[100];
int c[100];

bool test(int n){
	if(p[0] < n){
		return 0;
	}
	int crnt = n;
	int lftover = c[0]-n;
	for(int i = 1; i<=50; i++){
		if(p[i] < crnt){
			lftover = max(0, lftover-(crnt-p[i]));
			crnt = p[i];
		}
		lftover += c[i]-crnt;
	}
	return lftover == 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		long long n;
		cin >> n;
		for(long long k = 0; 1; k++){
			if(n >= (1LL<<k) && n < (1LL<<(k+1))){
				c[k]++;
				if(__builtin_popcountll(n) == 1){
					p[k]++;
				}
				break;
			}
		}
	}
	bool done = 0;
	for(int t = 1; t<=N; t++){
		if(test(t)){
			done = 1;
			cout << t << " ";
		}
	}
	if(!done){
		cout << -1;
	}
}