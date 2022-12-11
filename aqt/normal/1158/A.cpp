
// Problem : A. The Party and Sweets
// Contest : Codeforces - Codeforces Round #559 (Div. 1)
// URL : https://codeforces.com/contest/1158/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
long long b[100005], g[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=N; i++){
		cin >> b[i];
	}
	for(int j = 1; j<=M; j++){
		cin >> g[j];
	}
	int mxb = *max_element(b+1, b+1+N);
	int mng = *min_element(g+1, g+1+M);
	if(mxb > mng){
		cout << -1 << "\n";
		return 0;
	}
	long long tot = 0;
	sort(b+1, b+1+N);
	for(int i = 1; i<=N-2; i++){
		tot += b[i] * M;
	}
	if(mxb == mng){
		tot += b[N-1] * M;	
	}
	else{
		tot += b[N-1] * (M-1);
		tot += b[N];
	}
	tot += accumulate(g+1, g+1+M, 0LL);
	cout << tot;
}