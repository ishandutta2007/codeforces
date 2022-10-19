#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,p,q,num[3010],pos[3010];
ll res;int sum;
vector<int>v[3010];
int nex[3010],las[3010];
void ins(int p){
	if(num[p]++)return;
	for(int i=p-1;i>=0;i--)if(num[i]){las[p]=i,nex[i]=p;break;}
	for(int i=p+1;i<=m+1;i++)if(num[i]){nex[p]=i,las[i]=p;break;}
}
void del(int p){
	int tot=0,j=pos[p];
	--num[p];
	for(int i=p;i>=j&&i;i=las[i])tot+=num[i];
	if(tot<q){
		sum-=pos[p]*(nex[p]-p);
		j=pos[p]=las[j],tot+=num[j];
		sum+=pos[p]*(nex[p]-p);
	}
	for(int i=nex[p];i<=m;i=nex[i]){
		tot+=num[i];
		while(tot-num[j]>=q)tot-=num[j],j=nex[j];
		if(j>p)break;
		sum-=pos[i]*(nex[i]-i);
		pos[i]=j;
		sum+=pos[i]*(nex[i]-i);
	}
	if(!num[p])nex[las[p]]=nex[p],las[nex[p]]=las[p];
}
void rein(int x){nex[las[x]]=x,las[nex[x]]=x,num[x]++;}
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1,x,y;i<=p;i++)scanf("%d%d",&x,&y),v[x].push_back(y);
	num[0]=num[m+1]=1,nex[0]=m+1,las[0]=0,las[m+1]=0,nex[m+1]=m+1;
	for(int l=n;l;l--){
		for(auto x:v[l])ins(x);
//		for(int x=0;x!=m+1;x=nex[x])printf("%d ",x);puts("");
//		for(int x=m+1;x!=0;x=las[x])printf("%d ",x);puts("");
		sum=0;
		for(int i=nex[0];i<=m;i=nex[i]){
			pos[i]=0;int tot=0;
			for(int j=i;j;j=las[j])if((tot+=num[j])>=q){pos[i]=j,sum+=(nex[i]-i)*j;break;}
		}
		for(int r=n;r>=l;r--){
//			printf("[%d,%d]%d\n",l,r,sum);
			res+=sum;
			for(auto x:v[r])del(x);
		}
		for(int r=l;r<=n;r++)for(auto it=v[r].rbegin();it!=v[r].rend();it++)rein(*it);
	}
	printf("%lld\n",res);
	return 0;
}