//Will it FST?
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define mp make_pair

using namespace std;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
typedef long long ll;
typedef pair<int,int> P;
ll dp[25][5];
int a[25],k;
ll dfs(int cur,bool tig,int num){
	if(cur == 0) return 1;
	if(!tig && dp[cur][num] >= 0) return dp[cur][num];
	ll res = 0;
	if(tig){
		if(a[cur] == 0) res += dfs(cur - 1,true,num);
		else{
			res += dfs(cur - 1,false,num);
			if(num > 0){
				for(int i=1;i<a[cur];i++){
					res += dfs(cur - 1,false,num - 1);
				}
				res += dfs(cur - 1,true,num - 1);
			}
		}
	}else{
		res += dfs(cur - 1,false,num);
		if(num > 0){
			for(int i=1;i<=9;i++){
				res += dfs(cur - 1,false,num - 1);
			}
		}
	}
	if(!tig) dp[cur][num] = res;
	return res;
}
ll calc(ll r){
	memset(dp,-1,sizeof(dp));
	k = 0;
	while(r > 0){
		a[++k] = r % 10;
		r /= 10;
	}
	return dfs(k,true,3);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll l,r;
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",calc(r) - calc(l - 1));
	}
	return 0;
}