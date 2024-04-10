#include<iostream>
#include<algorithm>
using namespace std;
    
int main()
{
    int n,i,j,k,x,c;
    cin>>n;
    int a[6][n+2],b[n],cc[6][n+2];
    for(i=1;i<=(n+1);i++)
    {            
         for(j=0;j<=5;j++)
         {
              cc[j][i]=0;
              a[j][i]=0;
         }
         b[i-1]=0;
    }
    for(i=1;i<=n;i++)
    {
         a[0][i]=i;
         cc[0][i]=i;             
         for(j=1;j<=4;j++)
         {
              cin>>a[j][i];
              cc[j][i]=a[j][i];
         }
         b[i-1]=a[4][i]*100+i;
    }
    sort(b,b+n);
    for(i=0;i<n;i++)                    
    {
         k=b[i]%100;
         for(j=0;j<=4;j++)
         {
              swap(a[j][i+1],cc[j][k]);
         }
    }
    for(i=1;i<=n;i++)
    {
         
         k=0;
         for(j=n;j>i;j--)
         {                     
              for(c=1;c<4;c++)
              {
                   if(a[c][i]>=a[c][j])c=10;
              }
              if(c==4)k=1,j=i+1;
         }
         if(k==0)x=i,i=n+2;
    }     
    cout<<a[0][x]<<endl;               
    //system("pause");
    //return 0;
}