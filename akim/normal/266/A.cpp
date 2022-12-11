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
 string s;
 int i,o=0,l;
 cin>>l;getline(cin,s);
 getline(cin,s);
 for(i=0;i<l-1;i++){if(s[i]==s[i+1]){o++;}}
 cout<<o;
}