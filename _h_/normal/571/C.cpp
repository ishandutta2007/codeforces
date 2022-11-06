#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <string>
#include <cmath>
#include <utility>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <stack>
#include <queue>
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < (b); ++i)
#define rrep(i,a,b) for(int i = int(b)-1; i >= int(a); --i)
#define allof(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define max(a,b) ((a)<(b)?(b):(a))
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vi ans(m+1,-1);
	vector<bool> vis(n+1);
	vector<vi> varToClause(m+1), clauseToLit(n+1);
	vi clauseDeg(n+1);
	stack<int> degOne;
	rep(i,1,n+1){
		scanf("%d",&clauseDeg[i]);
		if(clauseDeg[i] == 0){
			printf("NO\n");
			return 0;
		}
		if(clauseDeg[i] == 1)
			degOne.push(i);
		int v;
		rep(j,0,clauseDeg[i]){
			scanf("%d",&v);
			clauseToLit[i].push_back(v);
			varToClause[abs(v)].push_back(v < 0 ? -i : i);
		}
	}
	while(!degOne.empty()){
		int c = degOne.top();
		degOne.pop();
		if(vis[c])
			continue;
		vis[c] = 1;
		int lit = 0;
		for(int v : clauseToLit[c]){
			if(ans[abs(v)] == (v > 0)){
				c = -1;
				break;
			}
			if(ans[abs(v)] == -1)
				lit = v;
		}
		if(c < 0)
			continue;
		if(lit == 0){
			printf("NO\n");
			return 0;
		}
		ans[abs(lit)] = lit > 0;
		int c2 = varToClause[abs(lit)].size() > 1 &&
		 abs(varToClause[abs(lit)][0]) == c ? varToClause[abs(lit)][1]
		 : varToClause[abs(lit)][0];
		if(abs(c2) == c || vis[abs(c2)])
			continue;
		if((c2 > 0) == ans[abs(lit)]){
			vis[abs(c2)] = 1;
			continue;
		}
		if(--clauseDeg[abs(c2)] == 1)
			degOne.push(abs(c2));
	}
	rep(i,1,n+1){
		int j = i;
		while(!vis[j]){
			vis[j] = 1;
			int lit = 0;
			for(int v : clauseToLit[j])
				if(ans[abs(v)] == -1)
					lit = v;
			if(lit == 0){
				printf("wtf\n");
				return 0;
			}
			ans[abs(lit)] = lit>0;
			int c2 = varToClause[abs(lit)].size() > 1 &&
		 abs(varToClause[abs(lit)][0]) == j ? varToClause[abs(lit)][1]
		 : varToClause[abs(lit)][0];
		 	if(abs(c2) == j || vis[abs(c2)])
		 		break;
		 	if(ans[abs(lit)] == (c2 > 0)){
		 		vis[abs(c2)] = 1;
		 		break;
		 	}
		 	j = abs(c2);
		}
	}
	printf("YES\n");
	rep(i,1,m+1)
		printf("%d",ans[i]==-1?0:ans[i]);
	printf("\n");
}