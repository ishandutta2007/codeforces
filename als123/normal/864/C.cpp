#include <bits/stdc++.h>
using namespace std;
int A,B,F,K;
int main()
{
  scanf("%d%d%d%d",&A,&B,&F,&K); int last=B; int ans=0;
  while(K)
  {
    if(K>1)
    {
      last-=F;if(last<0){printf("-1\n"); return 0;}
      if(last<2*(A-F)) last=B,ans++;
      last-=A-F;if(last<0){printf("-1\n"); return 0;}
      K--;
    }
    else if(K)
    {
      last-=F; if(last<0){printf("-1\n"); return 0;}
      if(last<A-F) last=B,ans++;
      last-=A-F; if(last<0){printf("-1\n"); return 0;}
      K--;
    }

    if(K>1)
    {
      last-=A-F;if(last<0){printf("-1\n"); return 0;}
      if(last<2*F) last=B,ans++;
      last-=F; if(last<0){printf("-1\n"); return 0;}
      K--;
    }
    else if(K)
    {
      last-=A-F;if(last<0){printf("-1\n"); return 0;}
      if(last<F) last=B,ans++;
      last-=F; if(last<0){printf("-1\n"); return 0;}
      K--;
    }
  }
  return printf("%d\n",ans),0;
}