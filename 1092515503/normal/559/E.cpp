#include<bits/stdc++.h>
using namespace std;
int n,m,f[110][310];
pair<int,int>p[110];
vector<int>v;
int L[110],P[110],R[110],res;
#define bs(x) lower_bound(v.begin(),v.end(),x)-v.begin()+1
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second),v.push_back(p[i].first),v.push_back(p[i].first-p[i].second),v.push_back(p[i].first+p[i].second);
	sort(p+1,p+n+1),sort(v.begin(),v.end()),v.resize(m=unique(v.begin(),v.end())-v.begin());
	for(int i=1;i<=n;i++)L[i]=bs(p[i].first-p[i].second),P[i]=bs(p[i].first),R[i]=bs(p[i].first+p[i].second);
	for(int i=1;i<=n;i++){
		memcpy(f[i],f[i-1],sizeof(f[i]));
		for(int j=P[i];j<=R[i];j++)f[i][j]=max(f[i][j],f[i-1][P[i]]+v[j-1]-v[P[i]-1]);
		for(int j=i;j;j--){
			int Rmax=(j==i?P[j]:R[j]);
			if(Rmax<P[i])continue;
			int Lmin=(j==i?L[j]:P[j]);
			for(int k=j+1;k<=i;k++)Lmin=min(Lmin,L[k]);
			for(int k=Lmin;k<=Rmax;k++)f[i][k]=max(f[i][k],f[j-1][Lmin]+v[k-1]-v[Lmin-1]);
		}
		for(int j=1;j<=m;j++)f[i][j]=max(f[i][j],f[i][j-1]);
	}
	for(int i=1;i<=m;i++)res=max(res,f[n][i]);
	printf("%d\n",res);
	return 0;
}