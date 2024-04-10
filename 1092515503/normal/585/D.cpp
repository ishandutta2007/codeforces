#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second
#define mp make_pair
typedef long long ll;
int n,half,a[30],b[30],c[30];
ll tri=1;
pair<int,ll>res=mp(0x80808080,0);
struct node{
	int stp;
	pii u,v;
	node(int A=0,int B=0,int C=0,int D=0,int E=0){stp=A,u=mp(B,C),v=mp(D,E);}
};
map<pii,pii>m;
queue<node>q;
void bfsI(){
	q.push(node(1,0,0,0,0));
	while(!q.empty()){
		node w=q.front();q.pop();
		if(w.stp>half){
			if(m.find(w.u)==m.end())m[w.u]=w.v;
			else m[w.u]=max(m[w.u],w.v);
			continue;
		}
		q.push(node(w.stp+1,w.u.x-b[w.stp],w.u.y-c[w.stp],w.v.x,w.v.y*3+0));
		q.push(node(w.stp+1,w.u.x+a[w.stp],w.u.y+a[w.stp]-c[w.stp],w.v.x+a[w.stp],w.v.y*3+1));
		q.push(node(w.stp+1,w.u.x+a[w.stp]-b[w.stp],w.u.y+a[w.stp],w.v.x+a[w.stp],w.v.y*3+2));
	}
}
void bfsII(){
	q.push(node(half+1,0,0,0,0));
	while(!q.empty()){
		node w=q.front();q.pop();
		if(w.stp>n){
			if(m.find(w.u)==m.end())continue;
//			printf("(%d %d)->(%d,%d)\n",m[w.u].x,m[w.u].y,w.v.x,w.v.y);
			res=max(res,mp(m[w.u].x+w.v.x,tri*m[w.u].y+w.v.y));
			continue;
		}
		q.push(node(w.stp+1,w.u.x+b[w.stp],w.u.y+c[w.stp],w.v.x,w.v.y*3+0));
		q.push(node(w.stp+1,w.u.x-a[w.stp],w.u.y-a[w.stp]+c[w.stp],w.v.x+a[w.stp],w.v.y*3+1));
		q.push(node(w.stp+1,w.u.x-a[w.stp]+b[w.stp],w.u.y-a[w.stp],w.v.x+a[w.stp],w.v.y*3+2));
	}
}
string ss[3]={"MW","LW","LM"};
stack<int>stk;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	half=(n>>1);
	for(int i=half+1;i<=n;i++)tri*=3;
	bfsI(),bfsII();
	if(res.x==0x80808080){puts("Impossible");return 0;}
//	printf("%d,%d\n",res.x,res.y);
	for(int i=0;i<n;i++)stk.push(res.y%3),res.y/=3;
	while(!stk.empty())cout<<ss[stk.top()]<<endl,stk.pop();
	return 0;
}