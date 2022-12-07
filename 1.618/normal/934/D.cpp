#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
ll p,k;
ll ans[1005],kk;
int main(){
	scanf("%I64d%I64d",&p,&k);
	ll r = -k;
	while(p!=0){
    ll v = p % r;
    ll l = p / r;
    if(v < 0){
      l++;
      v -= r;
    }
    ans[++kk] = v;
    p = l;
  }
	printf("%d\n",kk);
	for(int i = 1;i<=kk;i++){
		printf("%d",ans[i]);
		if(i==kk) printf("\n");
		else printf(" ");
	}
	return 0;
}