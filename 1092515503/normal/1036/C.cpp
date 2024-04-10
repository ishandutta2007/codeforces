#include<bits/stdc++.h>
using namespace std;
#define int long long
int _1,num[20],f[20][5][2],a,b;
int dfs(int pla,int tot,bool lim){
	if(tot>=4)return 0;
	if(!pla)return 1;
	if(f[pla][tot][lim]!=-1)return f[pla][tot][lim];
	int res=0;
	for(int i=0;i<=(lim?num[pla]:9);i++)res+=dfs(pla-1,tot+(i!=0),lim&&(i==num[pla]));
	return f[pla][tot][lim]=res;
}
int part(int ip){
	int top=0;
	while(ip)num[++top]=ip%10,ip/=10;
	memset(f,-1,sizeof(f));
	return dfs(top,0,1);
}
signed main(){
	scanf("%lld",&_1);
	while(_1--)scanf("%lld%lld",&a,&b),printf("%lld\n",part(b)-part(a-1));
	return 0;
}