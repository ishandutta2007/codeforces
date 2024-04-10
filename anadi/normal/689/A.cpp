#include <bits/stdc++.h>

using namespace std;

int n;
char s[20];
int war[] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
int nr[] = {2, 1, 2, 3, 1, 2, 3, 1, 2, 3};
int who[5][5];

bool exist(int a, int b){
	if(a == 4)
		return b == 2;
	if(a <= 0 || a > 3)
		return false;
	return b > 0 && b < 4;
}

bool check(int last){
	for(int i = 2; i <= n; ++i){
		int dy = war[s[i] - '0'] - war[s[i - 1] - '0'];
		int dx = nr[s[i] - '0'] - nr[s[i - 1] - '0'];
		int ny = war[last];
		int nx = nr[last];
		if(!exist(ny + dy, nx + dx))
			return false;
		ny += dy;
		nx += dx;
		last = who[ny][nx];
	}
	
	return true;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	who[1][1] = 1;
	who[1][2] = 2;
	who[1][3] = 3;
	who[2][1] = 4;
	who[2][2] = 5;
	who[2][3] = 6;
	who[3][1] = 7;
	who[3][2] = 8;
	who[3][3] = 9;
	who[4][2] = 0;
	for(int i = 0; i <= 9; ++i){
		if(i == s[1] - '0')
			continue;
		if(check(i)){
			puts("NO");
			return 0;
		}
	}
	
	puts("YES");
	return 0;
}