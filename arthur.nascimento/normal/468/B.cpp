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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<unsigned long long,unsigned long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

vector<int> L[100100];
int ans[100100];
int foi[100100];
long long v[100100];

int imp = 0;
long long a,b;

void dfs(int x,int liga){

	foi[x] = 1;
	int foi2 = 0;
	debug("dfs %d\n",v[x]);

	for(vector<int> :: iterator it = L[x].begin(); it < L[x].end(); it++) if(!foi[*it]){

		if(liga){
			if(b-v[x] == v[*it] || b-v[*it] == v[x])
				ans[x] = ans[*it] = 1;
			else assert(a-v[x] == v[*it] || a-v[*it] == v[x]);
		}
		dfs(*it,1-liga);
		foi2++;

	}

	if(foi2 == 0 && liga == 1)
		imp = 1;

}

int pai[100100];
int qnt[100100];
int find(int x){
	return pai[x] = (x==pai[x])?x:find(pai[x]);}
void merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	qnt[a] += qnt[b];
	pai[b] = a;
}

main(){

		int n;
		scanf("%d%I64d%I64d",&n,&a,&b);

		for(int i=0;i<n;i++)
			pai[i] = i, qnt[i] = 1;

		map<int,int> mp;

		for(int i=0;i<n;i++){
			scanf("%I64d",v+i);
			assert(mp.find(v[i]) == mp.end());
			mp[v[i]] = i;
		}

		int A = -1, B = -1;

		for(int i=0;i<n;i++){
			if(2*v[i] == a) A = i;
			if(2*v[i] == b) B = i;
			if(mp.find(a-v[i]) != mp.end()) if(2*v[i] != a){
				L[i].pb(mp[a-v[i]]); merge(i,mp[a-v[i]]);}
			if(mp.find(b-v[i]) != mp.end()) if(2*v[i] != b){
				L[i].pb(mp[b-v[i]]); merge(i,mp[b-v[i]]);}
		}

		debug("qnt = %d %d\n",qnt[find(A)],qnt[find(B)]);
		if(A+1 && B+1){
			if(qnt[find(A)]%2 == 1){
				foi[A] = 1;
				if(find(A) != find(B) && qnt[find(B)]%2 == 1){
					foi[B] = 1; ans[B] = 1;}
			}
			else if(qnt[find(B)]%2 == 1){
				foi[B] = 1;
				ans[B] = 1;
			}
		}
		else if(A+1){
			if(qnt[find(A)]%2 == 1) foi[A] = 1;}
		else if(B+1){
			if(qnt[find(B)]%2 == 1){
				foi[B] = 1;
				ans[B] = 1;
			}
		}

		for(int i=0;i<n;i++) if(!foi[i] && L[i].size() == 1){debug("begin %d\n",v[i]);
			dfs(i,1);}

		for(int i=0;i<n;i++) if(!foi[i])
			dfs(i,1);

		if(imp)
			printf("NO\n");
		else {
			printf("YES\n");
			for(int i=0;i<n;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}

}