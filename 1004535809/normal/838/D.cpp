#include<cstdio>
#define L long long
L M=1e9+7;L P(L x,L e){L R=1;for(;e;e/=2,x=x*x%M)(e&1)&&((R*=x)%=M);return R;}main(){L n,m;scanf("%d%d",&n,&m);printf("%d\n",2*P(n+1<<1,m-1)*(n+1-m)%M);}