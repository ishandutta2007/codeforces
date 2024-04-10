#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,num[200100],cnt[200100],mn=0x3f3f3f3f3f3f3f3f,qwq[200100][2],cst[200100][2];
vector<int>v;
signed main(){
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%I64d",&num[i]),v.push_back(num[i]);
	sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)cnt[lower_bound(v.begin(),v.end(),num[i])-v.begin()]++;
	for(int i=0;i<v.size();i++)if(cnt[i]>=k){puts("0");return 0;}
	qwq[0][0]=cnt[0],cst[0][0]=0;
	for(int i=1;i<v.size();i++){
		cst[i][0]=cst[i-1][0]+qwq[i-1][0]*(v[i]-v[i-1]);
		qwq[i][0]=qwq[i-1][0]+cnt[i];
		if(qwq[i][0]>=k)mn=min(mn,cst[i][0]-(qwq[i][0]-k));
	}
	qwq[v.size()-1][1]=cnt[v.size()-1],cst[v.size()-1][1]=0;
	for(int i=v.size()-2;i>=0;i--){
		cst[i][1]=cst[i+1][1]+qwq[i+1][1]*(v[i+1]-v[i]);
		qwq[i][1]=qwq[i+1][1]+cnt[i];
		if(qwq[i][1]>=k)mn=min(mn,cst[i][1]-(qwq[i][1]-k));
	}
	for(int i=1;i<v.size()-1;i++)if(qwq[i][0]<k&&qwq[i][1]<k)mn=min(mn,cst[i][0]+cst[i][1]-(n-k));
	printf("%I64d\n",mn);
	return 0;
}