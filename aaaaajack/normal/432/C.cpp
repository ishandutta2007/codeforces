#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<utility>
#define N 100100
using namespace std;
int a[N],pos[N],prime[N],gb[N][2]={0},pcnt=0;
bool isprime[N];
vector<pair<int,int> > ans;
void update(int x,int y){
	ans.push_back(make_pair(x,y));
	swap(a[x],a[y]);
	swap(pos[a[x]],pos[a[y]]);
}
	
int main(){
	int i,j,n,x,y,diff;
	memset(isprime,-1,sizeof(isprime));
	for(i=2;i<N;i++){
		if(isprime[i]){
			prime[pcnt++]=i;
			for(j=2;i*j<N;j++) isprime[i*j]=false;
		}
	}
	for(i=2;i<N;i+=2){
		for(j=0;j<pcnt;j++){
			if(isprime[i-prime[j]]){
				gb[i][0]=prime[j]-1;
				gb[i][1]=i-prime[j]-1;
				break;
			}
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
	for(i=1;i<=n;i++){
		if(pos[i]>i){
			if(pos[i]-i==1){
				update(i,i+1);
			}
			else{
				if((pos[i]-i)&1){
					update(pos[i]-1,pos[i]);
				}
				diff=pos[i]-i+2;
				update(i+gb[diff][0],pos[i]);
				update(i,i+gb[diff][0]);
			}
		}
		else if(pos[i]<i){
			if(pos[i]-i==-1){
				update(i-1,i);
			}
			else{
				if((i-pos[i])&1){
					update(pos[i],pos[i]+1);
				}
				diff=i-pos[i]+2;
				update(pos[i],pos[i]+gb[diff][0]);
				update(pos[i],i);
			}
		}
	}
	printf("%d\n",ans.size());
	for(i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}