#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 vector<long long int> vc;
 long long int n,p,i,mi=1000100000,mp=0;
 cin>>n>>p;p--;
 for(i=0;i<n;i++)
 {
  long long int x;
  cin>>x;
  vc.pb(x);
  if(x<mi){mi=x;mp=i;}else
  if(x==mi&&(p>=i||mp>p)){mi=x;mp=i;}
 }
 long long int vn=vc[mp]*n;for(i=0;i<n;i++){vc[i]-=mi;}
 for(;p!=mp;)
 {
  vn++;vc[p]--;
  p--;if(p==-1){p=n-1;}
 }
 vc[mp]=vn;
 for(i=0;i<n;i++)
 {cout<<vc[i]<<" ";}
}