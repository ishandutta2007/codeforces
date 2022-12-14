#include<bits/stdc++.h>
using namespace std;
vector<long long> cmax,cmin,safe;
long long n,m,k,q,x,y,ans;
vector<long long> now,nowcost,xt,xtcost;
const long long inf=1e16;
long long calcost(long long x,long long a,long long b,long long c,long long d){
	if(x==n-1)
		return min(calcost(-10,a,b,c,c),calcost(-10,a,b,c,b));
	//if(b==-1)
	//	return abs(a-d);
	return min(
	abs(a-b)+abs(b-c)+abs(c-d),
	abs(a-c)+abs(c-b)+abs(b-d));
}
void xtadd(long long x){
	xt.push_back(x);
	xtcost.push_back(inf);
}
void find(long long x){
	long long left=0,right=q-1,mid;
	while(left<=right){
		mid=(left+right)/2;
		if(safe[mid]==x){
			xtadd(safe[mid]);
			return;
		}
		else if(safe[mid]<x)
			left=mid+1;
		else
			right=mid-1;
	}
	if(right>=0)xtadd(safe[right]);
	if(left<q)xtadd(safe[left]);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k>>q;
	cmax.resize(n,-1);
	cmin.resize(n,inf);
	safe.resize(q);
	for(long long I=0;I<k;I++){
		cin>>x>>y;
		x--,y--;
		cmax[x]=max(cmax[x],y);
		cmin[x]=min(cmin[x],y);
	}
	while(n!=0 && cmax[n-1]==-1)n--;
	for(long long I=0;I<q;I++){
		cin>>safe[I];
		safe[I]--;
	}
	sort(safe.begin(),safe.end());
	now.push_back(0);
	nowcost.push_back(0);
	for(long long x=0;x<n;x++){
		if(cmax[x]!=-1){
			xt.clear();
			xtcost.clear();
			find(cmax[x]);
			find(cmin[x]);
			for(long long I=0;I<now.size();I++)
			for(long long j=0;j<xt.size();j++)
				xtcost[j]=min(xtcost[j],
				nowcost[I]+calcost(x,now[I],cmax[x],cmin[x],xt[j]));
			now.swap(xt);
			nowcost.swap(xtcost);
		}
		else if(x==0){
			xt.clear();
			xtcost.clear();
			find(0);
			xtcost[0]=calcost(0,0,0,0,xt[0]);
			now.swap(xt);
			nowcost.swap(xtcost);
		}
		for(long long I=0;I<now.size();I++)
			nowcost[I]++;
	}
	ans=inf;
	for(long long i=0;i<now.size();i++)
		ans=min(ans,nowcost[i]);
	cout<<ans-1<<endl;
}