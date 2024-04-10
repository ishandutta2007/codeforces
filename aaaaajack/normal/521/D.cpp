#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define N 100100
using namespace std;
struct frac{
	int num;
	long long n,d;
	frac(long long _n=0,long long _d=1,int _num=0):n(_n),d(_d),num(_num){}
	bool operator<(const frac &rf)const{
		int q=n/d,rq=rf.n/rf.d,r=n%d,rr=rf.n%rf.d;
		if(q<rq) return true;
		else if(q>rq) return false;
		if(r==0||rr==0) return r==0;
		return frac(rf.d,rr)<frac(d,r);
	}
};
long long a[N],b[N];
int mx[N],now[N],to[N],tp[N];
vector<int> add[N],mul[N],ans;
bool cmpb(int i,int j){
	return b[i]>b[j];
}
bool cmpt(int i,int j){
	return tp[i]<tp[j];
}
int main(){
	int k,n,m,cnt=0;
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=k;i++) scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d%I64d",&tp[i],&to[i],&b[i]);
		if(tp[i]==1&&(!mx[to[i]]||b[i]>b[mx[to[i]]])) mx[to[i]]=i;
		if(tp[i]==2) add[to[i]].push_back(i);
		if(tp[i]==3) mul[to[i]].push_back(i);
	}
	for(int i=1;i<=k;i++){
		if(mx[i]&&b[mx[i]]>a[i]) add[i].push_back(mx[i]),b[mx[i]]-=a[i];
		sort(add[i].begin(),add[i].end(),cmpb);
	}
	priority_queue<frac> pq;
	for(int i=1;i<=k;i++){
		if(!add[i].empty()){
			now[i]++;
			pq.push(frac(a[i]+b[add[i][0]],a[i],add[i][0]));
		}
		for(int j=0;j<mul[i].size();j++){
			pq.push(frac(b[mul[i][j]],1,mul[i][j]));
		}
	}
	while(!pq.empty()&&cnt<m){
		int app=pq.top().num,j=to[app];
		ans.push_back(app);
		pq.pop();
		if(tp[app]<=2){
			a[j]+=b[app];
			if(now[j]<add[j].size()){
				int nxt=add[j][now[j]++];
				pq.push(frac(a[j]+b[nxt],a[j],nxt));
			}
		}
		cnt++;
	}
	sort(ans.begin(),ans.end(),cmpt);
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}