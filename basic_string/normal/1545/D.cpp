#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1009;
ll a[N][N],s1[N],s2[N];
map<ll,int>m1;
int main(){
	int m,k,i,j;
	ll w1,w2,w;
	scanf("%d%d",&m,&k);
	for(i=1;i<=k;++i)for(j=1;j<=m;++j)scanf("%lld",a[i]+j),s1[i]+=a[i][j],s2[i]+=a[i][j]*a[i][j];
	for(i=1;i<k;++i)++m1[s1[i+1]-s1[i]];
	for(auto o:m1)if(o.second>1)w1=o.first;
	for(i=1;i<k;++i)if(s1[i+1]-s1[i]!=w1){j=i+1;break;}
	for(i=2;i<k;++i)if(i-1!=j&&i!=j&&i+1!=j){w2=s2[i-1]+s2[i+1]-s2[i]*2;break;}
	w=w1-s1[j]+s1[j-1];
	for(i=1;i<=m;++i)if(s2[j-1]+s2[j+1]-(s2[j]-a[j][i]*a[j][i]+(a[j][i]+w)*(a[j][i]+w))*2==w2){printf("%d %lld\n",j-1,a[j][i]+w);}
	return 0;
}