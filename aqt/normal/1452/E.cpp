
// Problem : E. Two Editorials
// Contest : Codeforces - Educational Codeforces Round 98 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1452/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int l[2005];
int r[2005];
int a[5005];
const int OFFSET = 2100;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=M; i++){
		cin >> l[i] >> r[i];
	}
	int ans = 0;
	for(int s = 1; s<=N-K+1; s++){
		fill(a, a+5000, 0);
		int tot = 0;
		for(int n = 1; n<=M; n++){
			int v = 0;
			if(r[n] >= s+K-1){
				v = max(0, min(s+K-1 - l[n] + 1, K));
			}
			else if(r[n] >= s){
				v = min(r[n] - l[n] + 1, r[n] - s + 1);
			}
			tot += v;
			int ll = l[n] + v - K;
			a[ll+1+OFFSET]++;
			a[l[n]+1+OFFSET]--;
			int rr = r[n] - v + 1;
			a[r[n]-K+1+1+OFFSET]--;
			a[rr+1+OFFSET]++;
		}
		partial_sum(a, a+5000, a);
		partial_sum(a, a+5000, a);
		/*
		cout << max_element(a, a+5000) - a - OFFSET << "\n";
		cout << s << " " << tot << " " << *max_element(a, a+5000) << "\n";
		for(int i = 1; i<=N; i++){
			cout << a[i+OFFSET] << " ";
		}
		cout << "\n";
		*/
		ans = max(ans, tot + *max_element(a, a+5000));
	}
	cout << ans;
}