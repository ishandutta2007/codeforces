#include<cstdio>
#include<deque>
#include<utility>
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
long long ndp[150010]={0},dp[150010]={0};
int main(){
	int i,j,n,m,d;
	long long a[301],b[301],t[301],ans;
	scanf("%d%d%d",&n,&m,&d);
	for(i=0;i<m;i++){
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&t[i]);
	}
	t[m]=t[m-1];
	for(i=0;i<m;i++){
		t[i]=t[i+1]-t[i];
	}
	for(i=m-1;i>=0;i--){
		deque<pair<long long,int> > Max;
		int s,e,k=1;
		for(j=1;j<=n;j++){
			s=(j-d*t[i]>0?j-d*t[i]:1);
			e=(j+d*t[i]<=n?j+d*t[i]:n);
			while(k<=e){
				while(!Max.empty()&&dp[k]>Max.back().first) Max.pop_back();
				Max.push_back(make_pair(dp[k],k));
				k++;
			}
			while(Max.front().second<s) Max.pop_front();
			ndp[j]=b[i]-abs(a[i]-j)+Max.front().first;
		}
		for(j=1;j<=n;j++) dp[j]=ndp[j];
	}
	ans=dp[1];
	for(i=2;i<=n;i++) if(dp[i]>ans) ans=dp[i];
	printf("%I64d\n",ans);
	return 0;
}