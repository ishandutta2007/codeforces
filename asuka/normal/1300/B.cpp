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
#define ll long long
#define N 500015
using namespace std;
int T,n,a[N]; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1;i <= n+n;++i) scanf("%d",&a[i]);
		sort(a+1,a+n+n+1);
		printf("%d\n",a[n+1]-a[n]);
	}
    return 0;
}