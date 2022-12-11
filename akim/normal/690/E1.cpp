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
using namespace std;    
const int N = 610, mod = int(1e9)  + 7;

int n,m;
int q;
int a[N][N];
string ans[N],s[N];

int main () {
	scanf("%d",&q);
	for(int k = 1; k <= q; k++){
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++){
			for(int j = 1;j <= m; j++){
				scanf("%d",&a[i][j]);
			}
		}
		int ok = 0;
		for(int i = 1; i <= m; i++){
			if(abs(a[n/2][i] - a[n/2+1][i]) <= 15) ok++;
		}
		if(ok * 100 >= 75 * m) puts("NO");
		else puts("YES");
	}

return 0;
}