#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
char s[200];
int main()
{
  ios::sync_with_stdio(false);
  int T;
  cin>>T;
  for (int i=1;i<=T;i++)
  {
    cin>>s;
    int l=strlen(s);
    int cnt1=0,cnt2=0,cnt3=0,t1=0,t2=0,t3=0;
    rep(i,1,l)
    {
      if (s[i-1]>='A'&&s[i-1]<='Z') cnt1++,t1=1;
      if (s[i-1]>='a'&&s[i-1]<='z') cnt2++,t2=1;
      if (s[i-1]>='0'&&s[i-1]<='9') cnt3++,t3=1;
    }
    if (t1+t2+t3==1)
    {
      if (t1) s[0]='0',s[1]='a';
      if (t2) s[0]='0',s[1]='A';
      if (t3) s[0]='a',s[1]='A';
    }
    if (t1+t2+t3==2)
    {
      if (cnt1>=2)
      {
        rep(i,1,l)
        {
          if (s[i-1]>='A'&&s[i-1]<='Z')
          {
            if (t2==0) s[i-1]='a';
            if (t3==0) s[i-1]='0';
            break;
          }
        }
      } else
      if (cnt2>=2)
      {
        rep(i,1,l)
        {
          if (s[i-1]>='a'&&s[i-1]<='z')
          {
            if (t1==0) s[i-1]='A';
            if (t3==0) s[i-1]='0';
            break;
          }
        }
      } else
      if (cnt3>=2)
      {
        rep(i,1,l)
        {
          if (s[i-1]>='0'&&s[i-1]<='9')
          {
            if (t1==0) s[i-1]='A';
            if (t2==0) s[i-1]='a';
            break;
          }
        }
      }
    }
    rep(i,1,l) cout<<s[i-1];
    cout<<endl;
  }
  return 0;
}