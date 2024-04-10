#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,d[100100],t[100100],s[100100],f[100100][110],qwq=0x3f3f3f3f3f3f3f3f,l,r,q[100100];
signed main(){
	scanf("%lld%lld%lld",&n,&m,&p),memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=2;i<=n;i++)scanf("%lld",&d[i]),d[i]+=d[i-1];
//	for(int i=1;i<=n;i++)printf("%lld ",d[i]);puts("");
	for(int i=1,x,y;i<=m;i++)scanf("%lld%lld",&x,&y),t[i]=y-d[x];
//	printf("%lld\n",res);
//	for(int i=1;i<=m;i++)printf("%lld ",t[i]);puts("");
	sort(t+1,t+m+1);
	for(int i=1;i<=m;i++)s[i]=s[i-1]+t[i];
//	for(int i=1;i<=m;i++)printf("%lld ",t[i]);puts("");
	f[0][0]=0;
	for(int j=1;j<=p;j++){
		l=r=0;
		for(int i=1;i<=m;i++){
			while(r-l&&(f[q[l]][j-1]-f[q[l+1]][j-1]+s[q[l]]-s[q[l+1]])>=(q[l]-q[l+1])*t[i])l++;
			f[i][j]=f[q[l]][j-1]+(i-q[l])*t[i]-(s[i]-s[q[l]]);
			while(r-l&&(f[q[r-1]][j-1]-f[q[r]][j-1]+s[q[r-1]]-s[q[r]])*(q[r]-i)>=(f[q[r]][j-1]-f[i][j-1]+s[q[r]]-s[i])*(q[r-1]-q[r]))r--;
			q[++r]=i;
		}
	}
	for(int i=1;i<=p;i++)qwq=min(qwq,f[m][i]);
	printf("%lld\n",qwq);
	return 0;
}