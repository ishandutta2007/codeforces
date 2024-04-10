
// Problem : D. Weird journey
// Contest : Codeforces - Codeforces Round #407 (Div. 2)
// URL : https://codeforces.com/contest/789/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int dgr[1000005];
int dsu[1000005];
bool used[1000005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		dsu[i] = i;
	}
	int C = 0;
	int cnt = 0;
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		if(!used[a]){
			C++;
		}
		used[a] = 1;
		if(!used[b]){
			C++;
		}
		used[b] = 1;
		if(a == b){
			cnt++;
			continue;
		}
		dgr[a]++, dgr[b]++;
		if(getrt(a) != getrt(b)){
			dsu[getrt(a)] = getrt(b);
			C--;
		}
	}
	long long ans = 1LL*cnt*(M-cnt) + 1LL*cnt*(cnt-1)/2;
	for(int n = 1; n<=N; n++){
		ans += 1LL * dgr[n] * (dgr[n]-1) / 2;
	}
	cout << (C == 1 ? ans : 0);
}