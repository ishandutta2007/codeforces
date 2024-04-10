#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int na,ma;
    cin>>na>>ma;
    
    bool**a=new bool*[na+1];
    
    for(int i=1;i<=na;i++)
    {
    a[i]=new bool[ma+1];
    for(int j=1;j<=ma;j++)
    {
            char t;
            cin>>t;
    a[i][j]=t-'0';
    }
    }
    
    int nb,mb;
    cin>>nb>>mb;
    
    bool**b=new bool*[nb+1];
    
    for(int i=1;i<=nb;i++)
    {
    b[i]=new bool[mb+1];
    for(int j=1;j<=mb;j++)
    {
            char t;
            cin>>t;
    b[i][j]=t-'0';
    }
    }
    int maxe=-1;
    int ansx=-nb,ansy=-mb;
    for(int x=-max(na,nb);x<=max(na,nb);x++)
    for(int y=-max(ma,mb);y<=max(ma,mb);y++)
    {
            int sum=0;
    for(int i=1;i<=na;i++)
    for(int j=1;j<=ma;j++)
    {
            if(i+x>0)
            if(j+y>0)
            if(i+x<=nb)
            if(j+y<=mb)
            {
                     if(a[i][j] && b[i+x][j+y])
                     sum++;
                     
            }
    }
    //cout<<"dafuq"<<endl;
    //cout<<sum<<' '<<x<<' '<<y<<endl;
    if(sum>maxe)
    {
               maxe=sum;
               ansx=x;
               ansy=y;
    }
    }
    cout<<ansx<<' '<<ansy<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}