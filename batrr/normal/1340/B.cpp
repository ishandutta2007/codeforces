#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 2010;
 

int n, k, a[N], b[N], nxt[N][N];
bool was[N][N], dp[N][N];
char s[N];
bool f(int i, int j){
	if(j < 0)
		return 0;
	if(was[i][j])
		return dp[i][j];
	was[i][j] = 1;
	if(i == n)
		return dp[i][j] = (j == 0);		
	for(int x = 9; x >= 0; x--){
		if((b[x] | a[i]) == b[x]){
			if(f(i + 1, j - __builtin_popcount(b[x] ^ a[i]))){
				dp[i][j] = 1;
				nxt[i][j] = x;
				break;
			}
		}
	}
	return dp[i][j];
}
int main()
{
	b[0] = (1<<8) - 2 - (1<<4);
	b[1] = (1<<3) + (1<<6);
	b[2] = (1<<8) - 2 - (1<<2) - (1<<6);
    b[3] = (1<<8) - 2 - (1<<2) - (1<<5);
    b[4] = (1<<8) - 2 - (1<<1) - (1<<5) - (1<<7);
    b[5] = (1<<8) - 2 - (1<<3) - (1<<5);
    b[6] = (1<<8) - 2 - (1<<3);
    b[7] = (1<<1) + (1<<3) + (1<<6);
	b[8] = (1<<8) - 2;
 	b[9] = (1<<8) - 2 - (1<<5);
  	for(int i = 0; i < 10; i++)
 		b[i] /= 2;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		for(int j = 0; j < 7; j++)
			a[i] = (a[i] << 1 | (s[6 - j] == '1'));
	}
	if(!f(0, k)){
		printf("-1");
		return 0;
	}
	for(int i = 0, j = k; i < n; i++){
		printf("%d", nxt[i][j]);
		j -= __builtin_popcount(b[nxt[i][j]] ^ a[i]);
	}
}