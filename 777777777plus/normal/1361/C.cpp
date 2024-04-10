#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (1<<20)+1;
const int M = 5e5+5;

int n;
int a[M],b[M];
int head[N],cnt;
int d[N],ans[N];
bool vis[N];
struct nd{
	int ne,to,id;
}e[N*2];

void in(int x,int y,int w){
	e[++cnt].to=y;e[cnt].ne=head[x];e[cnt].id=w;head[x]=cnt;
}

void dfs(int x,int f){
	for(int &i=head[x];i;i=e[i].ne){
		if(!vis[i>>1]){
			vis[i>>1]=1;
			int now=e[i].id;
			dfs(e[i].to,x);
			ans[++ans[0]]=now;
		}
	}
	return;
}

bool can(int k,bool flag){
	cnt=1;
	for(int i=0;i<k;++i){
		d[i]=0;
		head[i]=0;
	}
	for(int i=1,x,y;i<=n;++i){
		vis[i]=0;
		x=a[i]%k;y=b[i]%k;
//		if(flag)printf("%d %d\n",x,y); 
		in(x,y,i);in(y,x,-i);
		d[x]++;d[y]++;
	}
	for(int i=0;i<k;++i)
	if(d[i]&1){
		return 0;
	}
	ans[0]=0;
	for(int i=0;i<k;++i)
	if(head[i]){
		dfs(i,-1);
		break;
	}
	if(ans[0]!=n)return 0;
	if(!flag)return 1;
	for(int i=ans[0];i>=1;--i){
		if(ans[i]>0)printf("%d %d ",2*ans[i]-1,2*ans[i]);
		else printf("%d %d ",2*(-ans[i]),2*(-ans[i])-1);
	}
	printf("\n");
	return 1; 
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
	int l=0,r=20;
	while(l!=r){
		int mid=l+r+1>>1;
		if(can(1<<mid,0))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	int base=can(1<<l,1);
}