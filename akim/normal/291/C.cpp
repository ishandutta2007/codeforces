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
long long x[100100];
set<long long> st;
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long k=1,mask=0;k=k<<31ll;
 int n,m,i,f;
 scanf("%d%d\n",&n,&m);
 for(i=0;i<n;i++)
 {vector<long long> vc;
  string s;getline(cin,s);int ls=s.length();
  for(f=0;f<ls;f++){if(s[f]!='.'){if(f==0||s[f-1]=='.'){vc.pb(s[f]-'0');}else{vc[vc.size()-1]=vc[vc.size()-1]*10+(s[f]-'0');}}}
  x[i]=(((((vc[0]*256)+vc[1])*256)+vc[2])*256)+vc[3];
 }
 while(k>0)
 {mask+=k;k/=2;st.clear();
  for(i=0;i<n;i++){st.insert(mask&x[i]);}
  if(st.size()==m)
  {
   printf("%I64d.",mask/256/256/256);
   printf("%I64d.",mask/256/256%256);
   printf("%I64d.",mask/256%256);
   printf("%I64d\n",mask%256);
   return(0);
  }
 }
 printf("-1");
}