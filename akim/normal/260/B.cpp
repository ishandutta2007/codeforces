#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int mes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 map<string,int> mp;
 string s,otvs="";
 getline(cin,s);
 int l=s.length(),i,otv=0;
 for(i=9;i<l;i++)
 if(s[i]>='0'&&s[i]<='9'&&s[i-1]>='0'&&s[i-1]<='9'&&s[i-2]>='0'&&s[i-3]<='9'&&s[i-4]=='-'&&s[i-5]>='0'&&s[i-5]<='9'&&s[i-6]>='0'&&s[i-6]<='9'&&s[i-7]=='-'&&s[i-8]>='0'&&s[i-8]<='9'&&s[i-9]>='0'&&s[i-9]<='9')
 {
  int g=((s[i]-'0')+(s[i-1]-'0')*10+(s[i-2]-'0')*100+(s[i-3]-'0')*1000),m=((s[i-5]-'0')+(s[i-6]-'0')*10),d=((s[i-8]-'0')+(s[i-9]-'0')*10);
  if((g<=2015)&&(g>=2013)&&(m>0)&&(m<13)&&(mes[m]>=d)&&(0<d))
  {
   string t=s.substr(i-9,10);
   if(mp.count(t)==0){mp[t]=1;}else{mp[t]++;}
   if(mp[t]>otv){otv=mp[t];otvs=t;}
  }
 }
 cout<<otvs;
}