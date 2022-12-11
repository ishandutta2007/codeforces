
// Problem : F. Awesome Substrings
// Contest : Good Bye 2019
// URL : https://codeforces.com/contest/1270/problem/F
// Memory Limit : 512 MB
// Time Limit : 8000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
const int B = 450;
string s;
int arr[200005];
int pre[200005];
int rem[200005];
int lft[200005], rht[200005];
int mp[91000005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	N = s.size();
	fill(lft+1, lft+1+N, -1);
	for(int i = 1; i<=N; i++){
		arr[i] = s[i-1] - '0';
		pre[i] = arr[i] + pre[i-1];
		rht[pre[i]] = i;
		if(lft[pre[i]] == -1){
			lft[pre[i]] = i;
		}
	}
	long long ans = 0;
	for(int b = 1; b<=B; b++){
		for(int i = 1; i<=N; i++){
			ans += mp[pre[i]*b-i+N];
			mp[pre[i]*b-i+N]++;
		}
		for(int i = 1; i<=N; i++){
			mp[pre[i]*b-i+N] = 0;
		}
		int l = 1;
		for(int l = 1, r = 1; r<=N; r++){
			while(pre[r] - pre[l-1] > B){
				mp[pre[l-1]*b-l+1+N]--;
				l++;
			}
			ans -= mp[pre[r]*b-r+N];
			mp[pre[r]*b-r+N]++;
		}
		for(int i = l-1; i<=N; i++){
			mp[pre[i]*b-i+N] = 0;
		}
	}
	for(int b = 1; b<=B; b++){
		if(b > pre[N]){
			break;
		}
		for(int r = lft[b]; r<=N; r++){
			ans += rht[pre[r]-b]/b - (lft[pre[r]-b]-1)/b;
			ans += rht[pre[r]-b]%b >= r%b;
			ans -= (lft[pre[r]-b]-1)%b >= r%b;
		}
	}
	cout << ans << "\n";
}