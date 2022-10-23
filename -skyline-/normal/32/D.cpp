#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,k,maxi=0,maxj=0,maxr=0,i,j,r,a1,a2,a3,a4,min,s=0,g,t,f;
    cin>>n>>m>>k;
    char a[n][m];
    for(i=0;i<n;i++)
    {
         for(j=0;j<m;j++)
         {                                    
              cin>>a[i][j];
         }
    }
    min=(n-1)/2;
    t=(m-1)/2;
    if(t>min)t=min;
    for(r=1;r<=t;r++)
    {
       for(i=1;i<(n-1);i++)
       {
         for(j=1;j<(m-1);j++)
         {
              if(a[i][j]=='*')
              {
                   a1=i,a2=n-i-1,a3=j,a4=m-j-1;
                   min=a1;
                   if(a2<min)min=a2;
                   if(a3<min)min=a3;
                   if(a4<min)min=a4;
                   if(r<=min)
                   {
                        if((a[i][j-r]=='*')&&(a[i][j+r]=='*')&&(a[i-r][j]=='*')&&(a[i+r][j]=='*'))
                        {
                                     
                                     
                                          s++;
                                          if(s==k)
                                          {
                                               maxr=r,maxi=i,maxj=j;
                                               j=m,i=n,r=t+2;
                                          }
                                                                                                                  
                            }   
                        }
                   }
              }
         }
    }
    if(s<k)cout<<-1<<endl;
    else
    {
         maxi++;
         maxj++;
         cout<<maxi<<' '<<maxj<<endl;
         cout<<maxi-maxr<<' '<<maxj<<endl;
         cout<<maxi+maxr<<' '<<maxj<<endl;
         cout<<maxi<<' '<<maxj-maxr<<endl;
         cout<<maxi<<' '<<maxj+maxr<<endl;
    }
    //system("pause");
    return 0;
}