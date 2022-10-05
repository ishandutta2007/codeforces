#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void exgcd(int a,int b,int&d,int&x,int&y){b?(exgcd(b,a%b,d,y,x),y-=a/b*x):(d=a,x=1,y=0);}
const int N=2e5+3;
bool b[N];
vector<int>v[N];
int d[N],p[N],q[N];
int main(){
	int n,m,i,j,x,t=0;
	scanf("%d%d",&n,&m);
	while(n--)scanf("%d",&j),b[j]=1;
	for(i=0;i<m;++i)if(!b[i])v[gcd(i,m)].push_back(i);
	for(i=1;i<=m;++i){
		d[i]+=v[i].size();
		for(j=i+i;j<=m;j+=i)if(d[j]<d[i])d[j]=d[i],p[j]=i;
	}
	for(i=m;i;i=p[i])for(int j:v[i])q[++t]=j;
	printf("%d\n",t);
	if(t)for(printf("%d ",q[t]);t>1;printf("%d ",((x*1ll*q[--t]/i)%m+m)%m))exgcd(q[t],m,i,x,j);
	return 0;
}