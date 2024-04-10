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
#include <complex>

#define inf 999999999
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-5
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 1010

using namespace std;

int M[maxn][maxn];
int last[maxn][maxn];

int t[maxn];
int pos[maxn][maxn];

main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&M[i][j]);
			
	int low = 0, up = 1000000000;
	int cur = 0;
	
	while(low != up){
		
		int mid = (low+up+1)/2;
		
		for(int i=0;i<n;i++)
			t[i] = 0;
			
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(M[i][j] >= mid)
					pos[i][t[i]++] = j;
		
		int s2 = 0;
		
		for(int i=0;i<n;i++)
			s2 += t[i]*(t[i]-1);
			
		if(s2 > m*(m-1)){
			low = mid;
			continue;
		}
		
		cur++;
		int ok = 0;
		
		for(int i=0;i<n;i++)
			for(int a=0;a<t[i];a++)
				for(int b=a+1;b<t[i];b++){
					if(last[pos[i][a]][pos[i][b]] == cur)
						ok = 1;
					last[pos[i][a]][pos[i][b]] = cur;
				}
				
		if(ok)
			low = mid;
		else	
			up = mid-1;
			
	}
	
	printf("%d\n",low);
	
}