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
#define maxn 200200

using namespace std;

set<int> S;
set<pii> px[maxn];
set<pii> py[maxn];

int x[maxn];
int y[maxn];

int rx[maxn];
int ry[maxn];
int bx[maxn];
int by[maxn];

char ans[maxn];

int idx[maxn];

int v[maxn];
int len = 0;

void dfs(){
	u:
	if(len == 0){
		if(S.size() == 0)
			return;
		v[len++] = *(S.begin());
		idx[v[0]] = 0;
	}
	int u = v[len-1];
	if(len%2 == 0){
		if(px[x[u]].size() == 1){
			len--;
			S.erase(u);
			px[x[u]].erase(pii(y[u],u));
			py[y[u]].erase(pii(x[u],u));
			dfs();
			if(ry[y[u]] >= by[y[u]]){
				ans[u] = 'b';
				bx[x[u]]++;
				by[y[u]]++;
			}
			else {
				ans[u] = 'r';
				rx[x[u]]++;
				ry[y[u]]++;
			}
			goto u;
		}
		set<pii> :: iterator it = px[x[u]].find(pii(y[u],u));
		if(it == px[x[u]].begin()) it++;
		else it--;
		if(idx[it->second] != -1){
			int r = idx[it->second];
			if((len-r)%2 == 1) r++;
			for(int i=r;i<len;i++){
				if(i%2){
					ans[v[i]] = 'r';
					rx[x[v[i]]]++;
					ry[y[v[i]]]++;
					S.erase(v[i]);
					px[x[v[i]]].erase(pii(y[v[i]],v[i]));
					py[y[v[i]]].erase(pii(x[v[i]],v[i]));
				}
				else {
					ans[v[i]] = 'b';
					bx[x[v[i]]]++;
					by[y[v[i]]]++;
					S.erase(v[i]);
					px[x[v[i]]].erase(pii(y[v[i]],v[i]));
					py[y[v[i]]].erase(pii(x[v[i]],v[i]));
				}
			}
			len = r;
		}
		else {
			idx[it->second] = len;
			v[len++] = it->second;
		}
		goto u;
	}
	else {
		if(py[y[u]].size() == 1){
			len--;
			S.erase(u);
			px[x[u]].erase(pii(y[u],u));
			py[y[u]].erase(pii(x[u],u));
			dfs();
			if(rx[x[u]] >= bx[x[u]]){
				ans[u] = 'b';
				bx[x[u]]++;
				by[y[u]]++;
			}
			else {
				ans[u] = 'r';
				rx[x[u]]++;
				ry[y[u]]++;
			}
			goto u;
		}
		set<pii> :: iterator it = py[y[u]].find(pii(x[u],u));
		if(it == py[y[u]].begin()) it++;
		else it--;
		if(idx[it->second] != -1){
			int r = idx[it->second];
			if((len-r)%2 == 1) r++;
			for(int i=r;i<len;i++){
				if(i%2){
					ans[v[i]] = 'r';
					rx[x[v[i]]]++;
					ry[y[v[i]]]++;
					S.erase(v[i]);
					px[x[v[i]]].erase(pii(y[v[i]],v[i]));
					py[y[v[i]]].erase(pii(x[v[i]],v[i]));
				}
				else {
					ans[v[i]] = 'b';
					bx[x[v[i]]]++;
					by[y[v[i]]]++;
					S.erase(v[i]);
					px[x[v[i]]].erase(pii(y[v[i]],v[i]));
					py[y[v[i]]].erase(pii(x[v[i]],v[i]));
				}
			}
			len = r;
		}
		else {
			idx[it->second] = len;
			v[len++] = it->second;
		}
		goto u;
	}
	
}

main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",x+i,y+i);
		S.insert(i);
		px[x[i]].insert(pii(y[i],i));
		py[y[i]].insert(pii(x[i],i));
	}
	memset(idx,-1,sizeof(idx));
	dfs();
	for(int i=0;i<n;i++)
		printf("%c",ans[i]);
	printf("\n");
}