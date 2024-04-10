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

#define inf 99999999999999999LL
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
#define maxn 300300

using namespace std;

int val[maxn];
int f[maxn];
int v[maxn];

main(){

	int n,q;
	scanf("%d%d",&n,&q);

	for(int i=0;i<n;i++)
		scanf("%d",v+i);

	long long uu = 0;

	while(q--){
		int l,r;
		scanf("%d%d",&l,&r), l--, r--;
		if(l == r){
			printf("0\n");
			continue;
		}
		long long ans = abs(v[r]-v[r-1]);
		uu = ans;
		int top = 0;
		val[0] = (int)ans;
		f[0] = 1;
		for(int i=r-2;i>=l;i--){
			int novo = abs(v[i+1]-v[i]);
			int ss = 1;
			while(top && val[top] < novo){
				ss += f[top];
				uu -= (long long)f[top]*val[top];
				top--;
			}
			if(novo > val[0]){
				uu -= (long long)f[0]*val[0];
				f[0] += ss;
				val[0] = novo;
				uu += (long long)f[0]*val[0];
			}
			else {
				top++;
				f[top] = ss;
				val[top] = novo;
				uu += (long long)f[top]*val[top];
			}
			ans += uu;
		}
		printf("%I64d\n",ans);
	}

}