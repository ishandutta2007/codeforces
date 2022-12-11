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
int x[300]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 string s;getline(cin,s);int ls=s.length(),i;
 for(i=0;i<ls;i++){x[s[i]]++;}
 int q=-1;
 for(i=0;i<300;i++)
 {if(x[i]%2==1){q++;}}
 if(q%2==0||q==-1){printf("First");}else{printf("Second");}
}