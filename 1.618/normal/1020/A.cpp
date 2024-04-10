#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
int n,h,k,a,b;
int t1,f1,t2,f2;
int main(){
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d%d",&t1,&f1,&t2,&f2);
		int ans = abs(t1 - t2);
		if(ans == 0){
			printf("%d\n",abs(f1 - f2));
		}else if(f1 >= b && f2 >= b){
			printf("%d\n",ans + f1 - b + f2 - b);
		}else if(f1 <= a && f2 <= a){
			printf("%d\n",ans + a - f1 + a - f2);
		}else{
			printf("%d\n",ans + abs(f1 - f2));
		}
	}
	return 0;
}