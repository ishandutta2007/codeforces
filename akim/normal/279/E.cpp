#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 string s;getline(cin,s);s="00"+s;int ls=s.length(),otv=0,i;
 for(i=ls-1;i>=0;i--)
 {
  if(s[i]=='1')
  {
   if(s[i-1]=='1')
   {
    while(s[i]=='1'){i--;}
    s[i++]='1';
    otv++;
   }else{otv++;}
  }
 }
 printf("%d",otv);
// printf("%d %d",v1,q1+1+q0);
}