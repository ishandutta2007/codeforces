#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res;
int n,m,a[100100],b[100100],dsu[100100],las[100100];
int find(int x){return dsu[x]==x?x:dsu[x]=find(dsu[x]);}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return false;
	dsu[y]=x;
	return true;
}
struct node{
	int x,y,val;
	node(int X,int Y){x=X,y=Y,val=a[X]+b[Y];}
	friend bool operator <(const node &u,const node &v){return u.val<v.val;}
};
priority_queue<node>q;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),dsu[i]=i;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d",&x);
		while(x--)scanf("%d",&y),q.push(node(i,y));
	}
	while(!q.empty()){
		node i=q.top();q.pop();
		if(las[i.x]&&!merge(las[i.x],i.y))res+=i.val;
		else las[i.x]=i.y;
	}
	printf("%lld\n",res);
	return 0;
}