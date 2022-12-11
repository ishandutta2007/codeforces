#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int main()
{
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
 string s;
 getline(cin,s);
 bool lg=0;
 int l=s.length(),i;
 for(i=0;i<l-1;i++)
 {
  if(lg==0&&s[i]=='0'){lg=1;}else{cout<<s[i];}
 }
 if(lg==1){cout<<s[l-1];}
}