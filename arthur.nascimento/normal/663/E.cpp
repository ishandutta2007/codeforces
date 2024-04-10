#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 100100

typedef long long ll;
using namespace std;

char str[22][maxn];

int M[22][maxn];

int v[maxn];

int n,m;

bool cmp(int a,int b){
	for(int i=0;i<n;i++)
		if(str[i][a] != str[i][b])
			return str[i][a] < str[i][b];
	return 0;
}


int qlast[1<<22];
int mask[maxn];

int coisa[maxn][20];
int add[maxn][20];

int pref[maxn];


main(){

	scanf("%d%d",&n,&m);
	getchar();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			str[i][j] = getchar();
		getchar();
	}

	for(int i=0;i<m;i++)
		v[i] = i;

	sort(v,v+m,cmp);

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			M[i][j] = (str[i][v[j]]=='1')?1:0;

	int up = n/2;
	int down = n-up;

	if(n > 10){
		up = 8;
		down = n-up;
	}

	for(int j=0;j<(1<<n);j++)
		for(int i=up;i<n;i++)
			if(j & (1<<i))
				qlast[j]++;

	for(int j=0;j<m;j++)
		for(int i=0;i<n;i++)
			mask[j] += M[i][j] * (1<<i);


	int filter = (1<<up)-1;

	int ans = (int)n*m;

	for(int i=0;i<(1<<down);i++){

		
		int qnt = 0;
		int last = 0;

		for(int j=0;j<m;j++)
			if(j ==  m-1 || (mask[j]&filter) != (mask[j+1]&filter)){

				pref[qnt] = (mask[j]&filter);
				for(int k=0;k<20;k++)
					coisa[qnt][k] = 0;
				for(int k=last;k<=j;k++){
					coisa[qnt][__builtin_popcount(((mask[k]>>up)^i))]++;
				}

				for(int k=0;k<=up;k++){
					add[qnt][k] = 0;
					for(int l=0;l<=down;l++)
						add[qnt][k] += (ll)coisa[qnt][l] * min(l+k,n-l-k);
				}

				last = j+1;
				qnt++;

			}


		for(int ii=0;ii<(1<<up);ii++){

			int cur = 0;

			for(int j=0;j<qnt;j++)
				cur += add[j][__builtin_popcount(pref[j]^ii)];

			ans = min(ans,cur);

		}

	}

	cout << ans << endl;

}