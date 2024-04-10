#include<bits/stdc++.h>
#define N 100100
#define Q 1000000007
using namespace std;
vector<int> g[N],in[N],cl[N];
vector<bool> sm[N];
int sg[N],vis[N];
int main(){
	int n,m,k,u,v;
	unsigned int now[2]={1,0},tn[2];
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		while(k--){
			scanf("%d",&u);
			if(u>0) in[u].push_back(i);
			else in[-u].push_back(-i);
		}
	}
	for(int i=1;i<=n;i++){
		if(in[i].empty()) now[0]=(now[0]+now[0])%Q,now[1]=(now[1]+now[1])%Q;
		else if(in[i].size()==1) sg[abs(in[i][0])]++;
		else{
			bool tsm=(in[i][0]>0)==(in[i][1]>0);
			int x=abs(in[i][0]),y=abs(in[i][1]);
			if(x!=y){	
				g[x].push_back(y);
				sm[x].push_back(tsm);
				g[y].push_back(x);
				sm[y].push_back(tsm);
			}
			else{
				vis[x]=true;
				if(tsm) now[0]=now[1]=(now[0]+now[1])%Q;
				else swap(now[0],now[1]),now[0]=(now[0]+now[0])%Q,now[1]=(now[1]+now[1])%Q;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(g[i].size()==1&&!vis[i]){
			vis[i]=true;
			u=i;
			v=g[i][0];
			bool tsm=sm[i][0];
			unsigned int pn[2][2]={},nxt[2][2]={},pcn[2]={};
			if(sg[u]) pn[1][1]=pn[0][0]=1;
			else pn[0][0]=1;
			while(1){
				vis[v]=true;
				for(int pre=0;pre<2;pre++){
					for(int par=0;par<2;par++){
						for(int ch=0;ch<2;ch++){
							nxt[ch][par^ch^(pre==0&&ch==tsm)]+=pn[pre][par];
							nxt[ch][par^ch^(pre==0&&ch==tsm)]%=Q;
						}
					}
				}
				memcpy(pn,nxt,sizeof(pn));
				memset(nxt,0,sizeof(nxt));
				if(g[v].size()==1) break;
				else if(g[v][0]==u){
					u=v;
					tsm=sm[v][1];
					v=g[v][1];
				}
				else{
					u=v;
					tsm=sm[v][0];
					v=g[v][0];
				}
			}
			if(sg[v]){
				for(int pre=0;pre<2;pre++){
					for(int par=0;par<2;par++){
						for(int ch=0;ch<2;ch++){
							pcn[par^(ch&&pre==0)]+=pn[pre][par];
							pcn[par^(ch&&pre==0)]%=Q;
						}
					}
				}
			}
			else{
				pcn[0]=(pn[0][0]+pn[1][0])%Q;
				pcn[1]=(pn[0][1]+pn[1][1])%Q;
			}
			tn[0]=(1ULL*now[0]*pcn[0]+1ULL*now[1]*pcn[1])%Q;
			tn[1]=(1ULL*now[1]*pcn[0]+1ULL*now[0]*pcn[1])%Q;
			now[0]=tn[0];
			now[1]=tn[1];
		}
	}
	for(int i=1;i<=m;i++){
		if(vis[i]) continue;
		if(g[i].empty()){
			if(sg[i]==1) now[0]=now[1]=(now[0]+now[1])%Q;
			else{
				tn[0]=(now[0]+now[1]*3)%Q;
				tn[1]=(now[0]*3+now[1])%Q;
				now[0]=tn[0];
				now[1]=tn[1];
			}
		}
		else{
			vis[i]=true;
			u=i;
			v=g[i][0];
			bool tsm=sm[i][0];
			unsigned int pn[2][2][2]={},nxt[2][2][2]={};
			pn[0][0][0]=1;
			do{
				vis[v]=true;
				for(int pre=0;pre<2;pre++){
					for(int par=0;par<2;par++){
						for(int fst=0;fst<2;fst++){
							for(int ch=0;ch<2;ch++){
								nxt[ch][par^ch^(pre==0&&ch==tsm)][u!=i?fst:(ch==tsm)]+=pn[pre][par][fst];
								nxt[ch][par^ch^(pre==0&&ch==tsm)][u!=i?fst:(ch==tsm)]%=Q;
							}
						}
					}
				}
				if(g[v][0]==u){
					u=v;
					tsm=sm[v][1];
					v=g[v][1];
				}
				else{
					u=v;
					tsm=sm[v][0];
					v=g[v][0];
				}
				memcpy(pn,nxt,sizeof(pn));
				memset(nxt,0,sizeof(nxt));
			}while(v!=i);
			unsigned int pcn[2]={};
			for(int pre=0;pre<2;pre++){
				for(int par=0;par<2;par++){
					for(int fst=0;fst<2;fst++){
						for(int ch=0;ch<2;ch++){
							pcn[par^(pre==0&&ch==tsm)^(fst==0&&ch)]+=pn[pre][par][fst];
							pcn[par^(pre==0&&ch==tsm)^(fst==0&&ch)]%=Q;
						}
					}
				}
			}
			tn[0]=(1ULL*now[0]*pcn[0]+1ULL*now[1]*pcn[1])%Q;
			tn[1]=(1ULL*now[0]*pcn[1]+1ULL*now[1]*pcn[0])%Q;
			now[0]=tn[0];
			now[1]=tn[1];
		}
	}
	printf("%u\n",now[1]);
	return 0;
}