#include<bits/stdc++.h>
using namespace std;
int N;
long long fact[1010101];
const int MOD = 998244353;
int main()
{
  scanf("%d", &N);
  fact[0] = 1;
  for(int i=1; i<=N; ++i)
    fact[i] = i*fact[i-1]%MOD;
  long long ans = fact[N];
  long long qq = N;
  for(int i=1; i<=N-1; ++i)
  {
    ans = (ans+qq*(fact[N-i]-1))%MOD;
    qq = (qq*(N-i))%MOD;
  }
  printf("%lld\n", ans);
}