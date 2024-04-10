#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int qmax(int a, int b){
	return (a > b) ? a : b;
}

int T;
int n, k;
char s[200200];
int cnt[200200][30];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		scanf("%s", s);
		for(int i = 0; i + i < k; i++) rep(j, 26) cnt[i][j] = 0;
		for(int i = 0; i * k < n; i++){
			int pos = i * k;
			int j = 0;
			for(; j + j < k; j++) cnt[j][s[pos + j] - 'a']++;
			for(; j < k; j++) cnt[k - j - 1][s[pos + j] - 'a']++;
		}
		int ans = n;
		for(int i = 0; i + i < k; i++){
			int mx = 0;
			rep(j, 26) mx = qmax(mx, cnt[i][j]);
			ans -= mx;
		}
		cout << ans << endl;
	}
	return 0;
}