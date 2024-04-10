#include<bits/stdc++.h>
using namespace std;

int N, Q;
char a[101010];
int lo[101010][26];
char s1[252], s2[252], s3[252];
int l1, l2, l3;
int dp[252][252][252];
bool p(int x, char c)
{
  int v1, v2, v3;
  auto f = [&](){
    int A = 10101010;
    
    if(v1)
    {
      int dv = dp[v1-1][v2][v3];
      int L = dv==-1?-1:lo[dv][s1[v1]-'a'];
      if(L != -1) A = min(A, L);
    }
    if(v2)
    {
      int dv = dp[v1][v2-1][v3];
      int L = dv==-1?-1:lo[dv][s2[v2]-'a'];
      if(L != -1) A = min(A, L);
    }
    if(v3)
    {
      int dv = dp[v1][v2][v3-1];
      int L = dv==-1?-1:lo[dv][s3[v3]-'a'];
      if(L != -1) A = min(A, L);
    }
    
    if(A>=10101010) dp[v1][v2][v3] = -1;
    else dp[v1][v2][v3] = A;
  };
       
  
  if(x==1)
  {
    s1[++l1] = c;
    v1 = l1;
    for(v2=0; v2<=l2; ++v2)
      for(v3=0; v3<=l3; ++v3)
        f();
  }
  else if(x==2)
  {
    s2[++l2] = c;
    v2 = l2;
    for(v1=0; v1<=l1; ++v1)
      for(v3=0; v3<=l3; ++v3)
        f();
  }
  else if(x==3)
  {
    s3[++l3] = c;
    v3 = l3;
    for(v1=0; v1<=l1; ++v1)
      for(v2=0; v2<=l2; ++v2)
        f();
  }
  return dp[l1][l2][l3] != -1;
}
bool m(int x)
{
  if(x==1) --l1;
  if(x==2) --l2;
  if(x==3) --l3;
  return dp[l1][l2][l3] != -1;
}
int main()
{
  dp[0][0][0] = 0;
  scanf("%d%d", &N, &Q);
  scanf("%s", a+1);
  for(char c = 'a'; c <= 'z'; ++c)
  {
    int l = -1;
    for(int i=N; i>=-1; --i)
    {
      lo[i][c-'a'] = l;
      if(c == a[i]) l = i;
    }
    lo[0][c-'a'] = l;
  }
  for(int i=0; i<Q; ++i)
  {
    char c; scanf(" %c", &c);
    bool r;
    if(c == '+')
    {
      int i; scanf("%d %c", &i, &c);
      r = p(i, c);
    }
    else
    {
      int i; scanf("%d", &i);
      r = m(i);
    }
    if(r) puts("YES");
    else puts("NO");
  }
}