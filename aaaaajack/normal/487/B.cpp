#include<cstdio>
#include<deque>
#include<algorithm>
#define N 100100
#define inf 1023456789
using namespace std;
int dp[N],a[N];
int main(){
	int i,j,n,s,l;
	scanf("%d%d%d",&n,&s,&l);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	j=0;
	deque<int> M,m,ans;
	for(i=1;i<=n;i++){
		while(!M.empty()&&a[i]>=a[M.back()]) M.pop_back();
		while(!m.empty()&&a[i]<=a[m.back()]) m.pop_back();
		M.push_back(i);
		m.push_back(i);
		if(i>=l&&dp[i-l]<inf&&i-l>=j){
			while(!ans.empty()&&dp[i-l]<=dp[ans.back()]) ans.pop_back();
			ans.push_back(i-l);
		}
		while(a[M.front()]-a[m.front()]>s){
			j=min(M.front(),m.front());
			while(!M.empty()&&M.front()<=j) M.pop_front();
			while(!m.empty()&&m.front()<=j) m.pop_front();
			while(!ans.empty()&&ans.front()<j) ans.pop_front();
		}
		if(ans.empty()) dp[i]=inf;
		else dp[i]=dp[ans.front()]+1;
	}
	if(dp[n]>=inf) printf("%d\n",-1);
	else printf("%d\n",dp[n]);
	return 0;
}