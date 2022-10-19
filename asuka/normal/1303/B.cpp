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
int t,n,g,b;
//int max(int a,int b){
//	return a>b?a:b;
//}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&g,&b);
		int half = (n+1)/2;
		int ug = ((half+g-1)/g)-1,l = half - (g*ug);
		int ub = ug*b;
		if(ub + half >= n){
			printf("%lld\n",ug*(b+g)+l);
		}else{
			printf("%lld\n",n-ub-half+ug*(b+g)+l);
		}
	}
    return 0;
}