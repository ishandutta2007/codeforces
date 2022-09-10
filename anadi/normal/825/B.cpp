#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 11;
const int DX[] = {-1, 0, 1, 1};
const int DY[] = {1, 1, 1, 0};

char s[N][N];

inline bool ok(int x, int y){
	return 1 <= x && x <= 10 && 1 <= y && y <= 10 && s[x][y] == 'X';
}

inline bool checker(int x, int y, int dir){
	for(int i = 0; i < 5; ++i){
		if(!ok(x, y))
			return false;
		x += DX[dir], y += DY[dir];
	}
	
	return true;
}

inline bool check(){
	for(int i = 1; i <= 10; ++i)
		for(int j = 1; j <= 10; ++j)
			for(int k = 0; k < 4; ++k)
				if(checker(i, j, k))
					return true;
	return false;
}

int main(){
	for(int i = 1; i <= 10; ++i)
		scanf("%s", s[i] + 1);
	
	bool ans = false;
	for(int i = 1; i <= 10; ++i)
		for(int j = 1; j <= 10; ++j)
			if(s[i][j] == '.'){
				s[i][j] = 'X';
				ans |= check();
				s[i][j] = '.';
			}
	
	if(ans)	puts("YES");
	else	puts("NO");
	return 0;
}