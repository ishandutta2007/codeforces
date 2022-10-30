#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 30001
#define M 2050
using namespace std;
int cnt[N];
int table[N][M];
int bt(int now,int len){
	if(!len) return 0;
	int add=0;
	if(now+len+1<N) add=max(add,bt(now+len+1,len+1));
	if(now+len<N) add=max(add,bt(now+len,len));
	if(now+len-1<N) add=max(add,bt(now+len-1,len-1));
	return cnt[now]+add;
}
int dp(int now,int len){
	if(!len) return 0;
	if(table[now][len]>=0) return table[now][len];
	int add=0;
	if(now+len-1<N) add=max(add,dp(now+len-1,len-1));
	if(now+len<N) add=max(add,dp(now+len,len));
	if(now+len+1<N) add=max(add,dp(now+len+1,len+1));
	return table[now][len]=cnt[now]+add;
}
int main(){
	int i,d,x,n;
	scanf("%d%d",&n,&d);
	memset(table,-1,sizeof(table));
	for(i=0;i<n;i++) scanf("%d",&x),cnt[x]++;
	if(d>=M-50) printf("%d\n",bt(d,d));
	else printf("%d\n",dp(d,d));
	return 0;
}