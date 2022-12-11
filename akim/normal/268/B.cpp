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
 long long n,i;
 scanf("%I64d",&n);
 long long otv=n;
 for(i=1;i<n;i++){otv+=(n-i)*(i+1)-i;}
 cout<<otv;
}