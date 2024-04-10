#include <iostream>

using namespace std;

int main()
{
int c,kol,ma,j,n,i,m[5000];
cin>>n;
for (i=0; i<n; i++){
  cin>>m[i];
  }
for (j=0; j<n; j++){
  for (i=0; i<n-1; i++){
    if (m[i]>m[i+1]){
      c=m[i];
      m[i]=m[i+1];
      m[i+1]=c;
      }
    }
  }

ma=1;
kol=1;
for (i=1; i<n; i++){
  if (m[i]==m[i-1]){
    kol++;
    }
  else{
    kol=1;
    }
  if (kol>ma){
    ma=kol;
    }
  }
cout<<ma;
    return 0;
}