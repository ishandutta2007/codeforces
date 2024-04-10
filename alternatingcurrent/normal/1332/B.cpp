#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
const int lmt = 11;

int T;
int n;
int a[1010];
int color[1010];
bool used[1010];
int to[12];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		rep(i, n) scanf("%d", &a[i]);
		memset(used, 0, sizeof(used));
		rep(i, n){
			rep(j, lmt){
				if(a[i] % p[j] == 0){
					color[i] = j;
					used[j] = 1;
					break;
				}
			}
		}
		int cnt = 0;
		rep(i, lmt){
			if(used[i]) to[i] = cnt++;
		}
		printf("%d\n", cnt);
		rep(i, n) color[i] = to[color[i]] + 1;
		rep(i, n) printf("%d ", color[i]);
		printf("\n");
	}
	return 0;
}