#include<bits/stdc++.h>
using namespace std;
int N;
int a[1010110];
int main()
{
  scanf("%d", &N);
  for(int i=0; i<2*N; ++i) scanf("%d", a+i);
  sort(a, a+2*N);
  long long ans = 1LL*(a[N-1]-a[0])*(a[2*N-1]-a[N]);
  
  for(int i=0; i<=N; ++i)
  {
    ans = min(ans, 1LL*(a[N-1+i]-a[i])*(a[2*N-1]-a[0]));
  }
  
  printf("%lld\n", ans);
  return 0;
}