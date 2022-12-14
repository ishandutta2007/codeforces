#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int LEN = 3050;
char S[LEN], T[LEN];
int N, M;

int T1[LEN][LEN], T2[LEN][LEN];
int tb[LEN];
typedef pair<int, int> pii;
pii rec[LEN];

void solve(int i){
	if(i < 1) return;
		pii t = rec[i];
		solve(i - abs(t.first - t.second) - 1);
		printf("%d %d\n", t.first, t.second);
}
int main() {
	scanf("%s%s", S+1, T+1);
	N = strlen(S+1); M = strlen(T+1);
	
	for(int i = 1; i <= M; i++) {
		for(int j = 1; j <= N; j++) {
			if(T[i] == S[j]) T1[i][j] = T1[i-1][j-1] + 1;
			else T1[i][j] = 0;
		}
		for(int j = N; j > 0; j--) {
			if(T[i] == S[j]) T2[i][j] = T2[i-1][j+1] + 1;
			else T2[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= M; i++) {
		int cur = -1, x = -1, y = -1;
		for(int j = 1; j <= N; j++) {
			if(T1[i][j] > cur) cur = T1[i][j], x = j - T1[i][j] + 1, y = j;
			if(T2[i][j] > cur) cur = T2[i][j], x = j + T2[i][j] - 1, y = j;
		}
		if(cur == 0) tb[i] = -1;
		else if(tb[i-cur] >= 0) { 
			tb[i] = tb[i - cur] + 1;
			rec[i] = pii(x, y);
		}else tb[i] = -1;
	}
	
	printf("%d\n", tb[M]);
	if(tb[M] > 0)solve(M);
	return 0;
}