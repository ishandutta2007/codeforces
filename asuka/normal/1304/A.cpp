#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<queue>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#define int long long
#define N
using namespace std;
int t,x,y,a,b; 
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
		int dis = y-x,s = dis/(a+b);
		if(s*(a+b)==dis&&s>0) printf("%lld\n",s);
		else puts("-1"); 
	}
    return 0;
}