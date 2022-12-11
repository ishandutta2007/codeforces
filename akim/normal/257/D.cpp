#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
long long x[100100]={0};
bool z[100100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i,f;
 cin>>n;
 for(i=0;i<n;i++)
 {cin>>x[i];}
 long long s=0;
 for(f=n-1;f>=0;f--)
 {if(s<=0){s+=x[f];z[f]=1;}else{s-=x[f];z[f]=0;}}
 if(s>0)
 {
  for(i=0;i<n;i++){if(z[i]){cout<<"+";}else{cout<<"-";}}
 }else
 {
  for(i=0;i<n;i++){if(z[i]){cout<<"-";}else{cout<<"+";}}
 }
}