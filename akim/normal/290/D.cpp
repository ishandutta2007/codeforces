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
 int x,i;string s,t;t.clear();
 getline(cin,s);int ls=s.length();
 scanf("%d",&x);
 for(i=0;i<ls;i++)
 {
  if(s[i]<97){s[i]=s[i]+32;}
  if(s[i]<x+97){t+=s[i]-32;}
           else{t+=s[i];}
 }
 cout<<t;
}