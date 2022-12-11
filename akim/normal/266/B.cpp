#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define abs(a) ((a)<0?-(a):(a))
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,ti,i;
 string s,t;
 cin>>n>>ti;getline(cin,s);
 getline(cin,s);
 for(;ti>0;ti--)
 {
  t=s;
  for(i=0;i<n-1;i++){if(s[i]=='B'&&s[i+1]=='G'){swap(t[i],t[i+1]);}}
  s=t;
 }
 cout<<s;
}