#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
void readint(int &x){
	x = 0;
	char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar(); 
} 

int T;
int n, c;
int cnt[1000100];

int main(){
	readint(T);
	while(T--){
		readint(n), readint(c);
		rep(i, c + 1)
			cnt[i] = 0;
		rep(i, n){
			int a;
			readint(a);
			cnt[a]++;
		}
		rep(i, c + 1)
			cnt[i + 1] += cnt[i];
		bool ok = 1;
		for(int k = 1; k <= c; k++){
			if(cnt[k] - cnt[k - 1] == 0)
				continue;
			for(int i = 1; k * i <= c; i++){
				if(cnt[min(c, k * (i + 1) - 1)] - cnt[k * i - 1] != 0 && cnt[i] - cnt[i - 1] == 0){
					ok = 0;
					break;
				}
			}
		}
		cout << (ok ? "Yes" : "No") << endl;
	}
	return 0;
}