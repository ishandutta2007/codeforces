#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define Q 1000000007
using namespace std;
struct node{
	int next[25];
	int fail;
	int add;
	node(){
		memset(next,0,sizeof(next));
		fail=0;
		add=0;
	}
}ac[210];
int cnt=1;
int len[210];
int val[210];
int stm[210][210];
int dpn[210][210][510]={0};
int dpl[210][210][510]={0};
int dpr[210][210][510]={0};
int dpz[210][210][510]={0};
void init(int n,int m){
	int i,j,pre,now,temp;
	queue<int> q;
	for(i=0;i<n;i++){
		pre=0;
		for(j=0;j<len[i];j++){
			if(!ac[pre].next[stm[i][j]]){
				ac[pre].next[stm[i][j]]=cnt++;
			}
			pre=ac[pre].next[stm[i][j]];
		}
		ac[pre].add+=val[i];
	}
	q.push(0);
	while(!q.empty()){
		pre=q.front();
		q.pop();
		for(i=0;i<m;i++){
			if(ac[pre].next[i]){
				now=ac[pre].next[i];
				q.push(now);
				temp=ac[pre].fail;
				while(temp&&!ac[temp].next[i]) temp=ac[temp].fail;
				if(now!=ac[temp].next[i]) ac[now].fail=ac[temp].next[i];
				ac[now].add+=ac[ac[now].fail].add;
			}
		}
	}
}
int main(){
	int i,j,s,t,n,m,k,l[300]={0},r[300]={0},llen,rlen,temp,gt,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	scanf("%d",&llen);
	for(i=llen;i>=1;i--) scanf("%d",&l[i]);
	for(i=1;!l[i];i++) l[i]=m-1;
	l[i]--;
	if(!l[llen]) llen--;
	scanf("%d",&rlen);
	for(i=rlen;i>=1;i--) scanf("%d",&r[i]);
	for(i=0;i<n;i++){
		scanf("%d",&len[i]);
		for(j=0;j<len[i];j++) scanf("%d",&stm[i][j]);
		scanf("%d",&val[i]);
	}
	init(n,m);
	for(i=0;i<cnt;i++){
		for(j=0;j<=k;j++){
			dpl[0][i][j]=1;
			dpr[0][i][j]=1;
			dpn[0][i][j]=1;
		}
	}
	for(i=1;i<rlen;i++){
		for(j=0;j<cnt;j++){
			for(t=0;t<m;t++){
				temp=j;
				while(temp&&!ac[temp].next[t]){
					temp=ac[temp].fail;
				}
				gt=ac[temp].next[t];
				for(s=0;s<=k-ac[gt].add;s++){
					dpn[i][j][s]+=dpn[i-1][gt][s+ac[gt].add];
					dpn[i][j][s]%=Q;
					if(t<l[i]) dpl[i][j][s]+=dpn[i-1][gt][s+ac[gt].add];
					else if(t==l[i]) dpl[i][j][s]+=dpl[i-1][gt][s+ac[gt].add];
					dpl[i][j][s]%=Q;
					if(t<r[i]) dpr[i][j][s]+=dpn[i-1][gt][s+ac[gt].add];
					else if(t==r[i]) dpr[i][j][s]+=dpr[i-1][gt][s+ac[gt].add];
					dpr[i][j][s]%=Q;
					if(t) dpz[i][j][s]+=dpn[i-1][gt][s+ac[gt].add];
					dpz[i][j][s]%=Q;
				}
				if(!t){
					for(s=0;s<=k;s++){
						dpz[i][j][s]+=dpz[i-1][j][s];
						dpz[i][j][s]%=Q;
					}
				}
			}
		}
	}
	for(t=1;t<r[rlen];t++){
		ans+=dpn[rlen-1][ac[0].next[t]][ac[ac[0].next[t]].add];
		ans%=Q;
	}
	ans+=dpr[rlen-1][ac[0].next[t]][ac[ac[0].next[t]].add];
	ans%=Q;
	ans+=dpz[rlen-1][0][0];
	ans%=Q;
	//printf("%d\n",ans);
	if(llen){
		for(t=1;t<l[llen];t++){
			ans-=dpn[llen-1][ac[0].next[t]][ac[ac[0].next[t]].add];
			ans=(ans+Q)%Q;
		}
		ans-=dpl[llen-1][ac[0].next[t]][ac[ac[0].next[t]].add];
		ans=(ans+Q)%Q;
		ans-=dpz[llen-1][0][0];
		ans=(ans+Q)%Q;
	}
	printf("%d\n",ans);
	return 0;
}