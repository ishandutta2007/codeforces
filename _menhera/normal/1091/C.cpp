#include<bits/stdc++.h>
using namespace std;
int N; 
set<long long> S;
long long f(int a)
{
  int X = N/a;
  return X+1LL*a*X*(X-1)/2;
}
int main()
{
  scanf("%d", &N);
  for(int i=1; i*i<=N; ++i)
  {
    if(N%i == 0)
    {
      S.insert(f(i));
      S.insert(f(N/i));
    }
  }
  for(auto x: S) printf("%lld ", x);
  puts("");
}