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

#define inf (1<<30)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define pdp pair<double,pii>
#define pcc pair<char,char>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) //fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 200200	
#define mod 1000000007

#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

#define nxt fusrf

typedef long long ll;
using namespace std;

int pai[maxn];

int find(int x){
	return pai[x] = (x == pai[x]) ? x : find(pai[x]);
}

int v[maxn];
int ch[maxn];
int aux[maxn];
vector<int> L[maxn];

main(){	

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",v+i), v[i]--;
		aux[i] = v[i];
		pai[i] = i;
	}

	int ans = 0;
	int rt = -1;

	for(int i=0;i<n;i++)
		if(v[i] == i)
			rt = i;

	for(int i=0;i<n;i++){

		if(v[i] == i){
			if(rt == -1){
				rt = i;
				continue;
			}

			ans++;
			v[i] = rt;
			continue;
		}

		int a = find(i), b = find(v[i]);
		if(a != b){
			pai[a] = b;
			continue;
		}
		if(rt == -1){
			rt = i;
		}
		ans++;
		v[i] = rt;
	}
	ans = 0;
	for(int i=0;i<n;i++)
		if(aux[i] != v[i]) ans++;
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
		printf("%d ",v[i]+1);
	printf("\n");

}