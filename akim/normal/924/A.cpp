//Solution by Tima
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7; 

vector <int> rc, rb;

int n,m;
char s[55][55];

bool used[55][55];

int ux[55], uy[55];
int t;

void dfs(int x,int y){
	used[x][y] = 1;
	ux[x] = t;
	uy[y] = t;
	for(int j = 1; j <= n; j++){
		if(!used[j][y] && s[j][y] == '#') dfs(j, y);
	}
	for(int j = 1; j <= m; j++){
		if(!used[x][j] && s[x][j] == '#') dfs(x, j);
	}
}

int main () {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("\n%s", s[i] + 1);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!used[i][j] && s[i][j] == '#'){
				t++;
				dfs(i,j);
				for(int x = 1; x <= n; x++) if(ux[x] == t){
					for(int y = 1; y <= m; y++) if(uy[y] == t){
					    if(s[x][y] == '.'){
					    	cout << "No";
					    	return 0;
					    }
					}
				}
			}
		}
	}
	cout << "Yes";

return 0;
}