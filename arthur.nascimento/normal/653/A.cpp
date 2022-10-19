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
#define maxn 2002000
#define mod 1000000007

typedef long long ll;
using namespace std;

int v[maxn];

main(){

	set<int> S;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int u;
		scanf("%d",&u);
		S.insert(u);
	}

	int t = 0;
	for(set<int> :: iterator it = S.begin(); it != S.end(); it++)
		v[t++] = *it;
	int ans = 0;
	for(int i=0;i<n-2;i++)
		if(v[i+2]-v[i] == 2) ans = 1;
	printf("%s\n",ans?"YES":"NO");
}