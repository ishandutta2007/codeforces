#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (9999999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define mod 1000000007
#define maxn 10100

using namespace std;

char s[110][110];
char s1[110][110];

pii p[110*110];
int pc=0;

pii at[110*110];
int atc=0;

char mans[330][330];

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf(" %s",s[i]);

		vector<pii> ans;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
			
				s1[i][j] = s[i][j];
				
				if(s[i][j] == 'o')
					p[pc++] = pii(i,j);
				if(s[i][j] == 'x')
					at[atc++] = pii(i,j);
			}

		for(int i=-n;i<=n;i++)
			for(int j=-n;j<=n;j++){

				int ok = 1;
				int t1 = 0;
				for(int k=0;k<pc;k++){
					int x = p[k].first + i;
					int y = p[k].second + j;
					if(x < 0 || x >= n || y < 0 || y >= n) continue;
					if(s[x][y] != 'x' && s[x][y] != 'o') ok = 0;
					if(s[x][y] == 'x')t1 = 1;
				}

				if(ok == 0 || t1 == 0)continue;

				ans.pb(pii(i,j));

				for(int k=0;k<pc;k++){
					int x = p[k].first + i;
					int y = p[k].second + j;
					if(x < 0 || x >= n || y < 0 || y >= n) continue;
					s1[x][y] = 'X';
				}

			}

		int tt = 0;

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) if(s1[i][j] == 'x'){debug("! %d %d\n",i,j); tt = 1;}

		if(tt){
			printf("NO\n");
			return 0;
		}

		printf("YES\n");

		int mx = 155, my = 155;

		memset(mans,'.',sizeof(mans));

		mans[mx][my] = 'o';

		for(int i=0;i<ans.size();i++){
			mans[mx+ans[i].first][my+ans[i].second] = 'x';
		}

		for(int i=mx-n+1;i<=mx+n-1;i++){
			for(int j=my-n+1;j<=my+n-1;j++)
				printf("%c",mans[i][j]);
			printf("\n");
		}

}