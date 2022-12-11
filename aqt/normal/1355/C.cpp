
// Problem : C. Count Triangles
// Contest : Codeforces - Codeforces Round #643 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1355/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long M = 1000000;
long long diff[1000005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long A, B, C, D;
	cin >> A >> B >> C >> D;
	for(int i = A; i<=B; i++){
		diff[i+B]++;
		diff[i+C+1]--;
	}
	partial_sum(diff, diff+1+M, diff);
	partial_sum(diff, diff+1+M, diff);	
	long long ans = 0;
	for(int i = C; i<=D; i++){
		ans += diff[M] - diff[i];
	}
	cout << ans;
}