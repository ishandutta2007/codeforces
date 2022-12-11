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
map<char,int> br[1126000];
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 string s;getline(cin,s);
 string t;getline(cin,t);
 int i,f,k,kp,q,p,ls=s.length();scanf("%d",&k);
 q=1;
 for(i=0;i<ls;i++)
 {
  p=0;kp=0;
  for(f=i;f<ls;f++)
  {
   if(t[s[f]-'a']=='0'){kp++;}
   if(kp>k){break;}
   if(br[p][s[f]]==0)
   {
    br[p][s[f]]=q;
    p=q++;
   }else
   {
    p=br[p][s[f]];
   }
  }
 }
 printf("%d",q-1);
}