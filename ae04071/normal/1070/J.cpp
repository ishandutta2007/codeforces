#include <stdio.h>


int N, M, K;
char S[200050];
bool dp[30][30050];
void init(int N){
	for(int i = 0; i < 30; i++){
		for(int j = 0; j <= N; j++){
			dp[i][j] = false;
			if(j == 0) dp[i][j] = true;
		}
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int minn = 1234567890;
		int w[32] = {0,};
		scanf("%d %d %d", &N, &M, &K);
		scanf("%s", S);
		int minw = 123456789;
		for(int i = 0; S[i] != '\0'; i++){
			w[S[i]-'A'+1]++;
		}
		for(int i = 'A' - 'A' + 1; i <= 'Z' - 'A' + 1; i++){
			if(minw > w[i]) minw = w[i];
		}

		for(int cur = 'A' - 'A' + 1; cur <= 'Z' - 'A' + 1; cur++){
			if(w[cur] == 0) continue;
			init(N);
			dp[0][0] = 1;
			int lastj = 0;
			int tmp;
			for(int i = 1; i <= 'Z' - 'A' + 1; i++){
				for(int j = 0; j <= N; j++){
					if(i == cur){
						dp[i][j] = dp[i-1][j];
						continue;
					}
					if(dp[i-1][j] || (j >= w[i] && dp[i-1][j-w[i]])) {
						dp[i][j] = 1;
						if(j + w[cur] < N){1;}
						else{
							tmp = j + w[cur] + M - K;
							//printf("%c %d\n", cur - 1 + 'A', (N - lastj) * tmp);
							if(tmp < 0) tmp = 0;
							if(minn > (N - j) * tmp) minn = (N - j) * tmp;
						}
					}
				}
			}
			init(M);
			dp[0][0] = 1;
			lastj = 0;
			for(int i = 1; i <= 'Z' - 'A' + 1; i++){
				for(int j = 0; j <= M; j++){
					if(i == cur){
						dp[i][j] = dp[i-1][j];
						continue;
					}
					if(dp[i-1][j] || (j >= w[i] && dp[i-1][j-w[i]])){
						dp[i][j] = 1;
						if(j + w[cur] < M){1;}
						else{
							tmp = j + w[cur] + N - K;
							//printf("%c %d\n", cur - 1 + 'A', (N - lastj) * tmp);
							if(tmp < 0) tmp = 0;
							if(minn > (M - j) * tmp) minn = (M - j) * tmp;
						}
					}
				}
			}
			if(lastj + w[cur] < M) continue;
			tmp = lastj + w[cur] + N - K;
			//printf("%c %d\n", cur - 1 + 'A', (N - lastj) * tmp);
			if(tmp < 0) tmp = 0;
			if(minn > (M - lastj) * tmp) minn = (M - lastj) * tmp;
			
		}
		printf("%d\n", minn);
	}
}