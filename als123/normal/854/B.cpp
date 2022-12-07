#include <bits/stdc++.h>
using namespace std;
int N,K;
int main()
{
  scanf("%d%d",&N,&K);
  if ( (K==0) || (N==1) || (N==K)) printf("0");
  else printf("1");
  
  printf(" %d\n",min(K*2,N-K));
  return 0;
}