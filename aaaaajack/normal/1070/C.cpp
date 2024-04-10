#include<bits/stdc++.h>
#define N 1001000
#define M 200100
using namespace std;
long long fc[M],fp[M];
struct cl{
	int ev[2];
	int c;
	int p;
	bool operator<(cl rhs)const{return p<rhs.p;}
}cpu[M];
void upd(long long *f,int x,long long v){
	while(x<M){
		f[x]+=v;
		x+=x&-x;
	}
}
long long sum(long long *f,int x){
	long long r=0;
	while(x){
		r+=f[x];
		x-=x&-x;
	}
	return r;
}
inline int get_tm(int i){
	return cpu[i>>1].ev[i&1];
}
bool cmp(int i,int j){
	return get_tm(i)<get_tm(j);
}
pair<int,int> bs(int k){
	int s=1<<20,t=0,r=0;
	while(s){
		if(t+s<M&&r+fc[t+s]<k){
			r+=fc[t+s];
			t+=s;
		}		
		s>>=1;
	}
	return make_pair(t,r);
}
int main(){
	int n,k,m;
	long long ans=0;
	scanf("%d%d%d",&n,&k,&m);
	vector<int> tm(2*m);
	for(int i=1;i<=m;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&cpu[i].ev[j]);
		}
		cpu[i].ev[1]++;
		scanf("%d",&cpu[i].c);
		scanf("%d",&cpu[i].p);
	}
	sort(cpu+1,cpu+m+1);
	for(int j=0;j<m*2;j++){
		tm[j]=j+2;
	}
	sort(tm.begin(),tm.end(),cmp);
	int st=1;
	for(int i=0;i<tm.size();i++){
		int now=get_tm(tm[i]);
		int x=tm[i]>>1,ed=tm[i]&1;
		auto tmp=bs(k);
		long long val=sum(fp,tmp.first)+(tmp.first<m?1LL*(k-tmp.second)*cpu[tmp.first+1].p:0);
		//printf("%d %d %lld\n",st,now,val);
		ans+=val*(now-st);
		st=now;
		if(ed){
			upd(fc,x,-cpu[x].c);
			upd(fp,x,-1LL*cpu[x].p*cpu[x].c);
		}
		else{
			upd(fc,x,cpu[x].c);
			upd(fp,x,1LL*cpu[x].p*cpu[x].c);
		}
		//printf("next change: %d %d\n",cpu[x].c,cpu[x].p);
	}
	printf("%lld\n",ans);
	return 0;
}