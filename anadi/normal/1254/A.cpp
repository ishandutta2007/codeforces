#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 107;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int r, c, k;
char in[N][N];
char ans[N][N];

int cnt[N];
char character[N];

void Move(int &x, int &y){
	int dir = (x & 1) ? 1 : -1;
	y += dir;
	
	if(y == 0)
		++x, y = 1;
	if(y == c + 1)
		++x, y = c;
}

void solve(){
	scanf("%d %d %d", &r, &c, &k);
	for(int i = 1; i <= r; ++i)
		scanf("%s", in[i] + 1);
	
	int countRice = 0;
	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= c; ++j)
			countRice += in[i][j] == 'R';
	
	for(int i = 0; i < 10; ++i)
		character[i] = i + '0';
	for(int i = 0; i < 26; ++i)
		character[i + 10] = i + 'a';
	for(int i = 0; i < 26; ++i)
		character[i + 36] = i + 'A';
	
	int cur = (countRice + k - 1) / k;
	for(int i = 0; i < k; ++i){
		if((countRice - cur) < (cur - 1) * (k - i - 1))
			cur--;
		
		countRice -= cur;
		cnt[i] = cur;
	}
	
/*	for(int i = 0; i < k; ++i)
		printf("%d ", cnt[i]);
	puts("");
	*/
	int cx = 1, cy = 0;
	for(int i = 0; i < k; ++i){
		while(cnt[i]--){
			do{
				Move(cx, cy);
				ans[cx][cy] = character[i];
			}while(in[cx][cy] != 'R');
		}
		
//		printf("%d %d\n", cx, cy);
	}
	
	Move(cx, cy);
	while(cx <= r){
		ans[cx][cy] = character[k - 1];
		Move(cx, cy);
	}
	
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= c; ++j)
			printf("%c", ans[i][j]);
		puts("");
	}
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}