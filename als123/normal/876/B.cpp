#include <bits/stdc++.h>
using namespace std;
const int Maxn=100010;
int A[Maxn]; map<int,int>mp; int N,K,M;

map<int,int> :: iterator it;

int main()
{

  scanf("%d%d%d",&N,&K,&M); mp.clear(); for(int i=1;i<=N;i++) scanf("%d",&A[i]),mp[A[i]%M]++;
  int p=-1;
  for(it=mp.begin();it!=mp.end();++it)
  {
    if(it->second>=K){printf("Yes\n"); p=it->first; break;}
  }
  if(p==-1){printf("No\n"); return 0;} int s=0;
  for(int i=1;i<=N;i++)
  {
    if(A[i]%M==p)
    {
      printf("%d",A[i]),s++;
    if(s==K){printf("\n"); break;}
    else printf(" ");
} 
  }
  return 0;
}