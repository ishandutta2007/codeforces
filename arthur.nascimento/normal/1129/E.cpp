#include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define maxn 505
#define debug
using namespace std;

vector<int> L[maxn];
int foi[maxn];

int block[maxn];

int sz[maxn];

int dfs(int vx,int p=-1){

	if(!foi[vx] || block[vx])
		return 0;
		
	sz[vx] = 1;
	for(int i=0;i<L[vx].size();i++)
		if(L[vx][i] != p)
			sz[vx] += dfs(L[vx][i],vx);
	return sz[vx];
}

void clear(int vx,int p){
debug("clear %d\n",vx);
	block[vx] = 1;
	for(int i=0;i<L[vx].size();i++)
		if(L[vx][i] != p && !block[L[vx][i]])
			clear(L[vx][i],vx);
}

int main(){

	int n;
	scanf("%d",&n);
	
	vector<pii> ord;

	for(int i=2;i<=n;i++){
		debug("\n\n");
		printf("1\n");
		printf("%d\n",i);
		printf("%d\n",n-1);
		for(int j=1;j<=n;j++)
			if(j != i)
				printf("%d ",j);
		printf("\n");
		printf("1\n");
		fflush(stdout);
		
		int res;
		scanf("%d",&res);
		
		int s = res;
		
		debug("\n\n");
		printf("1\n");
		printf("%d\n",1);
		printf("%d\n",n-1);
		for(int j=1;j<=n;j++)
			if(j != 1)
				printf("%d ",j);
		printf("\n");
		printf("%d\n",i);
		fflush(stdout);
		
		scanf("%d",&res);
		
		s += res;
		
		ord.pb(pii(n-s,i));
	}
	
	sort(ord.begin(), ord.end());
	foi[1] = 1;
	
	vector<pii> ans;
	
	for(int k=0;k<ord.size();k++){
	
		int vx = ord[k].second;
		
		int qq, qtd;
		
		for(int i=1;i<=n;i++)
			block[i] = 0;
		
		while(1){
			qq = -1, qtd = 0;
			for(int i=1;i<=n;i++)
				if(foi[i] && !block[i]){
					qq = i;
					qtd++;
				}
			
			if(qtd == 1) break;
			
			dfs(qq);
			
			int ts = qq, p = qq;
			int go = 1;
			while(go){
				go = 0;
				for(int i=0;i<L[ts].size();i++)
					if(!block[L[ts][i]] && L[ts][i] != p)
						if(2*sz[L[ts][i]] > qtd){
							p = ts;
							ts = L[ts][i];
							go = 1;
							break;
						}
			}
			
			vector<pii> kids;
			
			int sumk = 0;
			for(int i=0;i<L[ts].size();i++)
				if(L[ts][i] != p && !block[L[ts][i]])
					sumk += sz[L[ts][i]];
			
			if(p != ts)
				kids.pb(pii(qtd-sumk-1,p));
			
			for(int i=0;i<L[ts].size();i++)
				if(L[ts][i] != p && !block[L[ts][i]])
					kids.pb(pii(sz[L[ts][i]],L[ts][i]));
					
			sort(kids.begin(), kids.end());
			
			vector<int> paint;
			
			int upto = -1;
			
			int ss = 0;
			for(int i=0;i<kids.size();i++){
				if(3*ss < qtd-1){
					paint.pb(kids[i].second);
					upto = i;	
				}
				ss += kids[i].first;
			}
			debug("\n\n");
			debug("qtd %d ts %d\n",qtd,ts);
			printf("1\n");
			printf("%d\n",vx);
			printf("%d\n",(int)paint.size());
			for(int i=0;i<paint.size();i++) printf("%d ",paint[i]);
			printf("\n");
			printf("%d\n",ts);
			fflush(stdout);
			int res;
			scanf("%d",&res);
			
			if(res == paint.size()){
				for(int i=0;i<=upto;i++)
					clear(kids[i].second,ts);
			}
			else {
				for(int i=upto+1;i<kids.size();i++)
					clear(kids[i].second,ts);
				if(qtd == 2){
					block[ts] = 1;debug("clear %d\n",ts);}
			}
		}
		
		L[vx].pb(qq);
		L[qq].pb(vx);
		foi[vx] = 1;
		ans.pb(pii(vx,qq));
		debug("%d -> %d\n",vx,qq);
		
	}
	
	printf("ANSWER\n");
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);

}