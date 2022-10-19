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

int v0[maxn];
char str[maxn];
int idx[maxn];

vector<int> L[maxn];
vector<int> nxt[26][maxn];

void dfs0(int x,int p=0){
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p){
			nxt[str[*it]-'a'][x].pb(*it);
			dfs0(*it,x);
		}
}

int cont = 1;
void dfs(vector<int> v){
	if(v.size() == 0)
		return;
	//debug("dfs ");
	//for(int i=0;i<v.size();i++)
	//	debug("%d ",1+v[i]);
	//debug("\n");
	for(int i=0;i<v.size();i++)
		idx[v[i]] = cont;
	cont++;
		
	for(int i=0;i<26;i++){
		vector<int> u;
		for(int j=0;j<v.size();j++)
			for(vector<int> :: iterator it = nxt[i][v[j]].begin(); it < nxt[i][v[j]].end(); it++)
				u.pb(*it);
		dfs(u);
	}
}

int best = -1;
int qnt = 0;

inline int reg(int v,int k){
	debug("reg %d %d\n",v+1,k);
	if(v0[v] + k > best){
		qnt = 0;
		best = v0[v] + k;
	}
	if(v0[v] + k == best)
		qnt++;
}

int ptr[maxn];

set<int> S[maxn];

int foi = 0;

void dfs2(int x,int p){
	int f = L[x].size();
	if(x) f--;

	if(f == 0){
		//debug("leaf %d is %d\n",x,idx[x]);
		//debug("leaf %d ptr %d\n",x+1,foi);
		S[foi].insert(idx[x]);
		ptr[x] = foi;
		foi++;
		reg(x,1);
		return;
	}

	int big = 0, sz = -1;
	//debug("dfs %d\n",x+1);
	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p){
			dfs2(*it,x);
			//if(x == 2) debug("!! %d - %d | %d %d\n",1+*it,ptr[*it],(int)S[ptr[*it]].size(),sz);
			if((int)S[ptr[*it]].size() > sz){
			//	if(x == 2) debug("okay\n");
				sz = S[ptr[*it]].size();
				big = ptr[*it];
			}
		}

	//debug("v %d big %d\n",x+1,big);

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++)
		if(*it != p && ptr[*it] != big){
			for(set<int> :: iterator it2 = S[ptr[*it]].begin(); it2 != S[ptr[*it]].end(); it2++)
				S[big].insert(*it2);
			S[ptr[*it]].clear();
		}
//	debug("vertex %d has ");
	S[big].insert(idx[x]);
	//for(set<int> :: iterator it = S[big].begin(); it != S[big].end(); it++)
	//	debug("%d ",*it);
	//debug("\n");
	reg(x,S[big].size());
	ptr[x] = big;
}
		

main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%d",v0+i);
	scanf(" %s",str);
	

	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b), a--, b--;
		L[a].pb(b);
		L[b].pb(a);
	}

	dfs0(0);
	vector<int> u;
	u.pb(0);
	dfs(u);
	dfs2(0,0);

	printf("%d\n%d\n",best,qnt);

}