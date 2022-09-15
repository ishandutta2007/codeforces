#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N; scanf("%d", &N);
  long long x = 0, y = 0;
  for(int i=0; i<2*N; ++i)
  {
    int a, b; scanf("%d%d", &a, &b);
    x += a; y += b;
  }  
  printf("%lld %lld\n", x/N, y/N);
}