#include <bits/stdc++.h>
using namespace std;
const int Maxn=110;
int L[Maxn],R[Maxn]; int fa[Maxn];
int Find(int x){return (fa[x]==x)?fa[x]:fa[x]=Find(fa[x]);}
int A[Maxn],B[Maxn]; int Alen,Blen;
int main()
{
  srand(time(0));
  int N; scanf("%d",&N);
  for(int i=1;i<=N;i++) fa[i]=i;
  for(int i=1;i<=N;i++) scanf("%d%d",&L[i],&R[i]);
  for(int i=1;i<=N;i++)
  {
    if(R[L[i]]==0) R[L[i]]=i;
    if(L[R[i]]==0) L[R[i]]=i;
  }
  
  for(int i=1;i<=N;i++)
  {
    int xx,yy;
    if(L[i])
    {
      xx=Find(L[i]);
      yy=Find(i);
      if(xx!=yy) fa[xx]=yy;
    }
    if(R[i])
    {
      xx=Find(R[i]);
      yy=Find(i);
      if(xx!=yy) fa[xx]=yy;
    }
  }

  Alen=Blen=0;
  for(int i=1;i<=N;i++) if(L[i]==0) A[++Alen]=i;
  for(int i=1;i<=N;i++) if(R[i]==0) B[++Blen]=i;
  for(int i=1;i<Alen;i++)
  {
    int x=rand()%Blen+1;
    while(Find(B[x])==Find(A[i]) || B[x]==0) x=rand()%Blen+1;
    L[A[i]]=B[x]; R[B[x]]=A[i];
    int xx=Find(A[i]); int yy=Find(B[x]);
    //printf("%d->%d\n",B[x],A[i]);
    fa[xx]=yy; B[x]=0;

    
  }
  //printf("\n");
  for(int i=1;i<=N;i++) printf("%d %d\n",L[i],R[i]);
  return 0;
}