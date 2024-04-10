#include<bits/stdc++.h>
using namespace std;
int n,m,t[1001000];
void add(int x,int y){
	while(x<=n)t[x]+=y,x+=x&-x;
}
int find(int k){
    int ans=0,cnt=0;
    for(int i=30;i>=0;i--){//ilog2(maxn),maxna
        ans+=(1<<i);
        if(ans>n||cnt+t[ans]>=k)ans-=(1<<i);//>=k
        else cnt+=t[ans];
    }
    return ++ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),add(x,1);
	for(int i=1,x;i<=m;i++){
		scanf("%d",&x);
		if(x>0)add(x,1);
		else add(find(-x),-1);
	}
	int x=find(1);
	printf("%d\n",x==n+1?0:x);
	return 0;
}