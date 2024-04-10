#include <bits/stdc++.h>

using namespace std;

string ll_to_str(long long v)
{
string s="";
if (v==0)
  return "0";
bool obr=false;
if (v<0)
  obr=true;
v=abs(v);
while (v>0)
  {
  short e=v%10;
  s+=char('0'+e);
  v/=10;
  }
reverse(s.begin(), s.end());
if (obr)
  s='-'+s;
return s;
}

int main()
{
long long k,p,i;
cin>>k>>p;

long long z=1;
long long ans=0;
while (k)
  {
//  cout<<k<<endl;
    {
//    cout<<"__"<<z<<endl;
    k--;
    string s1=ll_to_str(z);
    string s2=ll_to_str(z);
    reverse(s2.begin(), s2.end());
    s1+=s2;
    long long add=0;
    while (s1.size()>0)
      {
      add*=10;
      add+=(s1.back()-'0');
      s1.pop_back();
      }
    ans+=add;
    ans%=p;
    }
  z++;
  }

cout<<ans;


    return 0;
}