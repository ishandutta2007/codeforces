#include<bits/stdc++.h>
#define N 1000000
#define inf 999999999
using namespace std;
int n,m,ans[N+1],pans[N+1],fl[N+1],pcol,nxt[N+1],pre[N+1],cnt,g[N+1];
vector<int>ax,ay;
int que(int x,int y){
	int nans;
	printf("? %d %d\n",x,y);
	fflush(stdout);
//	nans=(x-y)*(x-y)-6*(x-y)+abs(x-y)+x*y+min(x,y);
//	cout<<nans<<'\n';
	cin>>nans;
	cnt++;
	return nans;
}
void pp(vector<int> nv){for(int i=0;i<nv.size();i++)cout<<nv[i]<<' ';cout<<endl;}
vector<int>reduce(vector<int>vx,vector<int>vy){
	if(vx.size()==1||vy.size()==1)return vy;
//	printf("r:\n"),pp(vx),pp(vy);
	int nk=0,nx=0,nn=vy.size(),st=0;
	for(int i=1;i<vy.size();i++)pre[i]=i-1,nxt[i-1]=i;nxt[vy.size()-1]=-1;
	while(nn>vx.size()){
//		printf("%d %d\n",nx,nk);
		int nt0=que(vx[nx],vy[nk]),nt1=que(vx[nx],vy[nxt[nk]]);
		if(nt0>=nt1){
			if(nk!=st)nxt[pre[nk]]=nxt[nk];
			if(nxt[nk]!=-1)pre[nxt[nk]]=pre[nk];
			if(nk!=st)nk=pre[nk];else nk=st=nxt[nk];
			nx--,nn--;if(nx<0)nx=0;
		}else if(nx==vx.size()-1){if(nxt[nxt[nk]]!=-1)pre[nxt[nxt[nk]]]=nk;nxt[nk]=nxt[nxt[nk]],nn--;}
		else nk=nxt[nk],nx++;
	}
	vector<int>nans;nans.clear();
	for(int i=st;i!=-1;i=nxt[i])nans.push_back(vy[i]);
//	if(!nans.size())cout<<"aaa\n";
//	printf("rr:");pp(nans);
	return nans;
}
void smoke(vector<int>vx,vector<int>vy){
//	printf("s:\n"),pp(vx),pp(vy);
	if(!vx.size())return;
	else if(vx.size()==1){
//		if(!vy.size())cout<<"aaa\n";
		for(int i=0;i<vy.size();i++){
			int na=que(vx[0],vy[i]);
			if(na<ans[vx[0]])ans[vx[0]]=na,pans[vx[0]]=vy[i];
		}
		return;
	}else if(vy.size()==1){
		for(int i=0;i<vx.size();i++)ans[vx[i]]=que(vx[i],vy[0]),pans[vx[i]]=vy[0];
		return;
	}else{
		vector<int>vix;vix.clear();
		for(int i=1;i<vx.size();i+=2)vix.push_back(vx[i]);
//		vector<int>viy=reduce(vix,vy);
		smoke(vix,reduce(vix,vy));
		for(int i=0;i<vy.size();i++)g[vy[i]]=i;
		for(int i=0;i<vx.size();i+=2){
//		if(vx[i]==40){cout<<"bbb\n"<<vy.size()<<'\n';for(int j=1;j<=n;j++)cout<<pans[j]<<' ';cout<<'\n';pp(vx);}
			int nl=0,nr=vy.size()-1;
			if(i)nl=g[pans[vx[i-1]]];
			if(i!=vx.size()-1)nr=g[pans[vx[i+1]]];
//			if(!nr)cout<<"ccc"<<i<<endl;
			for(int j=nl;j<=nr;j++){
				int na=que(vx[i],vy[j]);
				if(na<ans[vx[i]])ans[vx[i]]=na,pans[vx[i]]=vy[j];
			}
		}
	}
	
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)ans[i]=inf;
	for(int i=1;i<=n;i++)ax.push_back(i);
	for(int i=1;i<=m;i++)ay.push_back(i);
	smoke(ax,ay);
	int aans=inf;
	for(int i=1;i<=n;i++)aans=min(aans,ans[i]);
//	for(int i=1;i<=n;i++)printf("%d,%d ",ans[i],pans[i]);printf("\n");
	cout<<"! "<<aans<<'\n';
//	cout<<cnt<<'\n';
	return 0;
}