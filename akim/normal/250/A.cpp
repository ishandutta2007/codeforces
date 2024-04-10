#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
 int a[100],q=0,l=0,m=0,k=0,n,i;
 cin>>n;
 for(i=1;i<=n;i++)
 {
  cin>>l;k++;
  if(l<0){m++;}
  if(m==3){m=1;++q;a[q]=k-1;k=1;}
 }
 if(k>0){++q;a[q]=k;}
 cout<<q<<endl;
 for(i=1;i<=q;i++){cout<<a[i]<<" ";}
 return(0);
}