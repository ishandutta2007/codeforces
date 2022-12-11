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
 string s,t;
 getline(cin,s);int i,ls=s.length();bool log=0;
 for(i=0;i<ls;i++)
 {
  if(log){if(s[i]==34){log=0;cout<<"<"<<t<<">"<<endl;t.clear();}else{t+=s[i];}continue;}
  if(s[i]==' '){if(t.length()!=0){cout<<"<"<<t<<">"<<endl;t.clear();}continue;}
  if(s[i]==34){log=1;if(t.length()!=0){cout<<"<"<<t<<">"<<endl;t.clear();}continue;}
  t+=s[i];
 }
 if(t.length()!=0){cout<<"<"<<t<<">"<<endl;t.clear();}
}