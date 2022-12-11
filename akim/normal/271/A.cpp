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
 int n;
 scanf("%d",&n);n++;
 while(!(n/1000!=n/100%10&&n/1000!=n/10%10&&n/1000!=n%10&&
       n/100%10!=n/10%10&&n/100%10!=n%10&&
       n/10%10!=n%10)){n++;}
 printf("%d",n);
}