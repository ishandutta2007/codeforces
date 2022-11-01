#include<bits/stdc++.h>
using namespace std;

const int maxn=200111;
const int maxm=1000111;

int mx[maxn*3],dlt[maxn*3];
void push(int t){
	if(dlt[t]){
		mx[t*2]+=dlt[t];
		mx[t*2+1]+=dlt[t];
		dlt[t*2]+=dlt[t];
		dlt[t*2+1]+=dlt[t];
		dlt[t]=0;
	}
}
void modify(int l,int r,int v,int tl,int tr,int t){
	if(l<=tl&&tr<=r){
		mx[t]+=v;
		dlt[t]+=v;
		return;
	}
	int mid=(tl+tr)/2;
	push(t);
	if(l<=mid)modify(l,r,v,tl,mid,t*2);
	if(r>mid)modify(l,r,v,mid+1,tr,t*2+1);
	mx[t]=max(mx[t*2],mx[t*2+1]);
}

int n,m,p,a[maxn],ca[maxn],b[maxn],cb[maxn],x[maxn],y[maxn],z[maxn],val[maxn];
vector<int> monster[maxm],attack[maxm];

int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,ca+i);
	for(int i=1;i<=m;i++)scanf("%d%d",b+i,cb+i);
	for(int i=1;i<=p;i++)scanf("%d%d%d",x+i,y+i,z+i);
	for(int i=1;i<=n;i++)attack[a[i]].push_back(i);
	for(int i=1;i<=p;i++)monster[x[i]].push_back(i);
	
	vector<int> vs;
	for(int i=1;i<=m;i++)vs.push_back(b[i]);
	sort(vs.begin(),vs.end());vs.erase(unique(vs.begin(),vs.end()),vs.end());
	int sz=vs.size();
	for(int i=1;i<=sz;i++)val[i]=1000000001;
	for(int i=1;i<=m;i++){
		b[i]=upper_bound(vs.begin(),vs.end(),b[i])-vs.begin();
		val[b[i]]=min(val[b[i]],cb[i]);
		//modify(b[i],b[i],-cb[i],1,sz,1);
	}
	for(int i=1;i<=sz;i++)modify(i,i,-val[i],1,sz,1);
	int ans=-ca[1]-cb[1];
	for(int t=0;t<maxm;t++){
		for(auto i:attack[t])ans=max(ans,mx[1]-ca[i]);
		for(auto i:monster[t]){
			int id=upper_bound(vs.begin(),vs.end(),y[i])-vs.begin()+1;
			if(id<=sz)modify(id,sz,z[i],1,sz,1);
		}
	}
	printf("%d\n",ans);
	return 0;
}