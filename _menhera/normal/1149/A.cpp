#include<bits/stdc++.h>
using namespace std;
int N;
int v1, v2;
int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; ++i)
  {
    int t; scanf("%d", &t);
    if(t == 1) ++ v1;
    else ++v2;
  }
  if(v1 == 0)
  {
    for(int i=0; i<v2; ++i)
      printf("%d ", 2);
  }
  else if(v1 == 1)
  {
    if(N == 1)
    {
      printf("1");
    }
    else
    {
      printf("2 1 ");
      for(int i=0; i<N-2; ++i) printf("2 ");
    }
  }
  else if(v1%2==1)
  {
    for(int i=0; i<v1; ++i) printf("1 ");
    for(int i=0; i<v2; ++i) printf("2 ");
  }
  else 
  {
    if(v2 == 0)
    {
      for(int i=0; i<v1; ++i) printf("1 ");
    }
    else
    {
      printf("2 1 ");
      for(int i=0; i<v2-1; ++i) printf("2 ");
      for(int i=0; i<v1-1; ++i) printf("1 ");
    }
  }
  puts("");
  
}