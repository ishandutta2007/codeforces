#include<bits/stdc++.h>
#define N 300000
using namespace std;
int Q,q0,rt[N+1],prt,sz[N+1];
int ch[2*N+1][26],dq[2*N+1],lk[2*N+1],gq[2*N+1];
string q1[N+1];
queue<int>pol,qu;
int gnew(){int nt=pol.front();return pol.pop(),lk[nt]=gq[nt]=dq[nt]=0,memset(ch[nt],0,sizeof(ch[nt])),nt;}
void ycl(){
	for(int i=1;i<=2*N;i++)pol.push(i);
}
void trieadd(int u,int ns,int np,int nfl){
	if(np>=q1[ns].size()){
		if(nfl==1)dq[u]++;
		else dq[u]--;
		return;
	}
	if(!ch[u][q1[ns][np]-'a'])ch[u][q1[ns][np]-'a']=gnew();
	trieadd(ch[u][q1[ns][np]-'a'],ns,np+1,nfl);
}
void triemge(int u,int nu){
	dq[u]+=dq[nu];
	for(int i=0;i<26;i++){
		if(ch[nu][i]){
			if(!ch[u][i])ch[u][i]=gnew();
			triemge(ch[u][i],ch[nu][i]);
		}
	}
}
void trieclr(int u){
	pol.push(u);
	for(int i=0;i<26;i++)if(ch[u][i])trieclr(ch[u][i]);
}
void buildac(int u){
	while(!qu.empty())qu.pop();qu.push(u),gq[u]=dq[u];
	while(!qu.empty()){
		int nt=qu.front();qu.pop();
		for(int i=0;i<26;i++){
			if(ch[nt][i]){
				int ng=ch[nt][i],ni=lk[nt];
				for(;ni&&!ch[ni][i];ni=lk[ni]);
				if(ch[ni][i])lk[ng]=ch[ni][i];
				else lk[ng]=u;
				gq[ng]=gq[lk[ng]]+dq[ng];
				qu.push(ng);
			}
		}
	}
}
int getpp(int u,int ns){
	int np=u,nans=0;
	for(int i=0;i<q1[ns].size();i++){
		while(np&&!ch[np][q1[ns][i]-'a'])np=lk[np];
		if(!np)np=u;
		else np=ch[np][q1[ns][i]-'a'];
		nans+=gq[np];
	}return nans;
}
void cal0(){
	cin>>Q;
	for(int i=1;i<=Q;i++){
		cin>>q0>>q1[i];
		if(q0==1||q0==2){
			rt[++prt]=gnew();
			trieadd(rt[prt],i,0,q0),sz[prt]++;
			buildac(rt[prt]);
			while(prt>1&&sz[prt]>=sz[prt-1]){
				triemge(rt[prt-1],rt[prt]);
				trieclr(rt[prt]),buildac(rt[prt-1]);
				sz[prt-1]+=sz[prt],sz[prt]=0,rt[prt--]=0;
			}
		}else{
			int nans=0;
			for(int j=1;j<=prt;j++)nans+=getpp(rt[j],i);
			cout<<nans<<'\n';
			fflush(stdout);
		}
		
	}
}
signed main(){
	ycl();
	cal0();
	return 0;
}