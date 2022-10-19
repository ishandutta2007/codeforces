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
#define maxn 200200
#define mod 1000000007

typedef long long ll;
using namespace std;

int a[maxn];
int dg[maxn];
int b[maxn];

vector<int> L[maxn];

int check(int n,int m){

	for(int i=0;i<n;i++)
		L[i].clear();

	for(int i=0;i<n;i++)
		dg[i] = 0;

	for(int i=0;i<m;i++){
		L[a[i]].pb(b[i]);
		dg[b[i]]++;
	}

	queue<int> Q;

	for(int i=0;i<n;i++)
		if(dg[i] == 0)
			Q.push (i);

	int foi = 0;
	while(Q.size()){
		if(Q.size() > 1)
			return 0;
		int u =Q.front();
		Q.pop();
		for(vector<int> :: iterator it = L[u].begin(); it < L[u].end(); it++){
			dg[*it]--;
			if(dg[*it] == 0)
				Q.push(*it);
		}
	}
	return 1;

}

main(){

	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++)
		scanf("%d%d",a+i,b+i), a[i]--, b[i]--;

	if(check(n,m) == 0){
		printf("-1\n");
		return 0;
	}
	int low = 1, up = m;

	while(low != up){
		int mid = (low+up)/2;
		if(check(n,mid))
			up = mid;
		else
			low = mid+1;
	}

	printf("%d\n",low);

}