#include <bits/stdc++.h>
using namespace std;

#define mem(x,v) memset(x,v,sizeof(x))

const int M=1<<21;

int n,k,R,node,ls[M],rs[M],mi[M],mx[M],len[M],ans[M],res[M];
void push(int x){
	mi[x]=min(mi[ls[x]],mi[rs[x]]+len[x]/2);
	mx[x]=max(mx[ls[x]],mx[rs[x]]+len[x]/2);
	ans[x]=min(min(ans[ls[x]],ans[rs[x]]),mi[rs[x]]+len[x]/2-mx[ls[x]]);
}
void ins(int val,int bit,int &x){
	if(!x)len[x=++node]=1<<bit;
	if(!bit)return mi[x]=mx[x]=0,void();
	ins(val,bit-1,(val>>bit-1&1)?rs[x]:ls[x]),push(x);
}
void flip(int bit,int cur,int x){
	if(cur>bit)flip(bit,cur-1,ls[x]),flip(bit,cur-1,rs[x]),push(x);
	else swap(ls[x],rs[x]),push(x);
	
}
int main(){
	cin>>n>>k,mem(ans,0x3f),mem(mi,0x3f),mem(mx,0xcf);
	for(int i=1,a;i<=n;i++)cin>>a,ins(a,k,R); cout<<ans[R]<<" ";
	for(int i=1;i<1<<k;i++){
		int id=0;
		for(int j=0;j<k;j++){
			if((i-1>>k-j-1&1)!=(i>>k-j-1&1))flip(j,k-1,R);
			id+=(i>>j&1)<<(k-j-1);
		} res[id]=ans[R];
	} for(int i=1;i<1<<k;i++)cout<<res[i]<<" ";
	return 0;
}