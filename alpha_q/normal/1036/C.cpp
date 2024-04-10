#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll L,R;
ll memo[20][2][20];
ll dp(vector <ll> &x,int i,int tight,int count)
{
  if(i < 0)
  {
    return (count <= 3)?1:0;
  }
  if(memo[i][tight][count]!=-1 && tight != 1)return memo[i][tight][count];

  ll new_tight,lim,p=0;
  lim = (tight == 1) ? x[i] : 9;
  for(int w=0;w<=lim;w++)
  {
    new_tight = (w == x[i]) ? tight:0;
    p+=dp(x,i-1,new_tight,(w>0)?count+1:count);
  }
  if(tight ==0)memo[i][tight][count]=p;
  return p;
}
bool test(ll a)
{
  ll cnt = 0;
  while(a!=0)
  {
    cnt += (a%10 != 0)?1:0;
    a/=10;
  }
  return (cnt>3)?0:1;
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%I64d%I64d",&L,&R);
    if(R-L <= 1000)
    {
      ll j=0;
      for(ll i = L; i <= R; i++)
      {
        if(test(i))j++;
      }
      printf("%I64d\n",j);
      continue;
    }
    L--;
    vector <ll> x;
    memset(memo,-1,sizeof memo);
    while(R!=0)
    {
      x.push_back(R%10);
      R/=10;
    }
    ll ans1 = dp(x,x.size()-1,1,0);

      memset(memo,-1,sizeof memo);
      x.clear();
      while(L!=0)
      {
        x.push_back(L%10);
        L/=10;
      }
      ll ans2 = dp(x,x.size()-1,1,0);
      printf("%I64d\n",ans1-ans2);
    }

  return 0;
}