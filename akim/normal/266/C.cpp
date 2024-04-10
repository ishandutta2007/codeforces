#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int rez[1100][1100]={0};
int x[1100]={0},y[1100]={0},z[1100][2],m;
vector<int> vc[3];
void sswap(int l,int r)
{
 int i;
 for(i=0;i<m;i++)
 {
  if(z[i][0]==l){z[i][0]=r;}else
  if(z[i][0]==r){z[i][0]=l;}
 }
}
void qsorts(int l,int r)
{
 int i=l,f=r,p=x[(l+r)/2];
 while(i<f)
 {
  while(x[i]<p){i++;}
  while(x[f]>p){f--;}
  if(i<=f){
           swap(x[i],x[f]);
           if(x[i]!=x[f]){vc[0].pb(1);vc[1].pb(i);vc[2].pb(f);sswap(i,f);}
           i++;f--;
          }
 }
 if(l<f){qsorts(l,f);}
 if(i<r){qsorts(i,r);}
}
void tswap(int l,int r)
{
 int i;
 for(i=0;i<m;i++)
 {
  if(z[i][1]==l){z[i][1]=r;}else
  if(z[i][1]==r){z[i][1]=l;}
 }
}
void qsortt(int l,int r)
{
 int i=l,f=r,p=y[(l+r)/2];
 while(i<f)
 {
  while(y[i]>p){i++;}
  while(y[f]<p){f--;}
  if(i<=f){
           swap(y[i],y[f]);
           if(y[i]!=y[f]){vc[0].pb(2);vc[1].pb(i);vc[2].pb(f);tswap(i,f);}
           i++;f--;
          }
 }
 if(l<f){qsortt(l,f);}
 if(i<r){qsortt(i,r);}
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i,f,p;
 cin>>n;m=n-1;
 for(i=0;i<m;i++){cin>>z[i][0]>>z[i][1];x[z[i][0]]++;y[z[i][1]]++;}
 qsorts(1,n);
 qsortt(1,n);
 int ff=1;
 for(i=1;i<=n;i++)
 {
  for(f=0;f<m;f++)
  {
   if(z[f][0]==i){if(z[f][1]>ff){vc[0].pb(2);vc[1].pb(z[f][1]);vc[2].pb(ff);tswap(z[f][1],ff);}ff++;}
  }
 }
 int sz=vc[0].size();
 cout<<sz<<endl;
 for(i=0;i<sz;i++)
 {
  cout<<vc[0][i]<<" "<<vc[1][i]<<" "<<vc[2][i]<<"\n";
 }
/*




 for(i=0;i<m;i++){rez[z[i][0]][z[i][1]]=1;}
 for(i=1;i<=n;i++,cout<<endl)
 {
  for(f=1;f<=n;f++)
  {
   cout<<rez[i][f];
  }
 }*/
}