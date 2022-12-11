#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int x[1000100];
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 string s;
 getline(cin,s);
 int l=0,n=s.length();
 int r=n-1,i;
 for(i=0;i<n;i++)
 {
  if(s[i]=='l'){x[r]=i+1;r--;}
  if(s[i]=='r'){x[l]=i+1;l++;}
 }
 for(i=0;i<n;i++)
 {
  cout<<x[i]<<endl;
 }
}