#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 101
char s[N];
int n;
int memo[N][N];
int f(int i, int j){
	if(memo[i][j]!=-1)return memo[i][j];
	int m = 0;
	if(s[i]&&s[j]&&s[i]==s[j]){
		m = 1+f(i+1, j+1);
	}
	return memo[i][j]=m;
}
int main(){
	memset(memo, 0xff, sizeof memo);
	gets(s);
	n = strlen(s);
	int m = 0;
	for(int i = 0; i < n; i ++)for(int j = i+1; j < n; j ++){
		m = max(m, f(i, j));
	}
	printf("%d\n", m);
	return 0;
}