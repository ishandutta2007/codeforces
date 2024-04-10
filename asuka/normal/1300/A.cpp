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
#define N 105
using namespace std;
int T,n,a[N]; 
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int cnt = 0,sum = 0;
		for(int i = 1;i <= n;++i) scanf("%d",&a[i]);
		for(int i = 1;i <= n;++i){
			if(a[i]==0){
				a[i]++;cnt++;
			}
			sum += a[i];
		}
		if(sum == 0) cnt++;
		printf("%d\n",cnt);
	}
    return 0;
}