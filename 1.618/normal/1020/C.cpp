#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 3005
using namespace std;
typedef long long ll;
int n,m,maxv,pre;
vector <int> voter[maxn];
ll calc(int num){
	ll res = 0;
	int buy = 0;
	priority_queue <int,vector<int>,greater<int> > que;
	while(!que.empty()) que.pop();
	for(int i=2;i<=m;i++){
		int siz = voter[i].size();
		if(siz >= num + pre){
			int b = siz - num - pre + 1;
			buy += b;
			for(int j=0;j<b;j++){
				res += voter[i][j];
			}
			for(int j=b;j<siz;j++) que.push(voter[i][j]);
		}else{
			for(int j=0;j<siz;j++){
				que.push(voter[i][j]);
			}
		}
	}
	if(buy > num) return (ll)1e13;
	for(int i=buy+1;i<=num;i++){
		int cur = que.top();
		que.pop();
		res += cur;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int p,c;
		scanf("%d%d",&p,&c);
		voter[p].push_back(c);
	}
	for(int i=1;i<=m;i++){
		if(i > 1) maxv = max(maxv,(int)voter[i].size());
		sort(voter[i].begin(),voter[i].end());
	}
	if(voter[1].size() > maxv){
		puts("0");
		return 0;
	}
	pre = voter[1].size();
	ll ans = (ll)1e13;
	for(int i=1;i<=maxv + 1;i++){
		ans = min(ans,calc(i));
	}
	printf("%I64d\n",ans);
	return 0;
}