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
#define sqr(a) ((a)*(a))
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,n1,n2;scanf("%d",&n);
 n1=abs(n)/10;n2=abs(n)/100*10+abs(n)%10;
 if(n<0){n1=-n1;n2=-n2;}
 printf("%d",max(n,max(n1,n2)));
}