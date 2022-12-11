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
 int n,m,i,o11=0,o12=0,o21=0,o22=0;
 cin>>n>>m;
 int vn=n,vm=m,k=n+m,pr=0;
 for(i=0;i<k;i++)
 {
  if(i%2==1)
  {
   if(pr==1)
   {
    if(vm>0){vm--;pr=2;o12++;}else{vn--;pr=1;o11++;}
   }else
   if(pr==2)
   {
    if(vn>0){vn--;pr=1;o12++;}else{vm--;pr=2;o11++;}
   }
  }else
  {
   if(pr==0)
   {
    if(vn>0){vn--;pr=1;}else{vm--;pr=2;}
   }else
   if(pr==1)
   {
    if(vn>0){vn--;pr=1;o11++;}else{vm--;pr=2;o12++;}
   }else
   if(pr==2)
   {
    if(vm>0){vm--;pr=2;o11++;}else{vn--;pr=1;o12++;}
   }
  }
 }
 pr=0;vn=n;vm=m;
 for(i=0;i<k;i++)
 {
  if(i&1)
  {
   if(pr==1)
   {
    if(vm>0){vm--;pr=2;o22++;}else{vn--;pr=1;o21++;}
   }else
   if(pr==2)
   {
    if(vn>0){vn--;pr=1;o22++;}else{vm--;pr=2;o21++;}
   }
  }else
  {
   if(pr==0)
   {
    if(vm>0){vm--;pr=2;}else{vn--;pr=1;}
   }else
   if(pr==1)
   {
    if(vn>0){vn--;pr=1;o21++;}else{vm--;pr=2;o22++;}
   }else
   if(pr==2)
   {
    if(vm>0){vm--;pr=2;o21++;}else{vn--;pr=1;o22++;}
   }
  }
 }
 if(o11>o21||(o11==o21&&o12<o21)){cout<<o11<<" "<<o12;}else
 if(o11<o21||(o11==o21&&o12>o21)){cout<<o21<<" "<<o22;}else{cout<<o11<<" "<<o12;}
}