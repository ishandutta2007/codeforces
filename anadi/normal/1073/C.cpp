#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

int n;
int pref[N][4];

char s[N];
int sx, sy;

bool ok(int from, int to){
	int x = pref[n][0] - pref[n][1];
	int y = pref[n][2] - pref[n][3];

	x -= pref[to][0] - pref[from - 1][0];
	x += pref[to][1] - pref[from - 1][1];
	y -= pref[to][2] - pref[from - 1][2];
	y += pref[to][3] - pref[from - 1][3];
	return abs(sx - x) + abs(sy - y) <= to - from + 1;
}

int main(){
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%d %d", &sx, &sy);
	
	if(abs(sx) + abs(sy) > n || n%2 != (abs(sx + sy))%2){
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < 4; ++j)
			pref[i][j] = pref[i - 1][j];

		if(s[i] == 'R')
			++pref[i][0];
		else if(s[i] == 'L')
			++pref[i][1];
		else if(s[i] == 'U')
			++pref[i][2];
		else
			++pref[i][3];
	}
	
	int wsk = 0; int res = n;
	for(int i = 1; i <= n; ++i){
		while(wsk < n && !ok(i, wsk))
			++wsk;
		
		if(ok(i, wsk))
			res = min(res, wsk - i + 1);
	}
	
	printf("%d\n", res);
	return 0;
}