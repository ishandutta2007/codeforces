//MM
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N (110)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");


ll n,a[N],dis1[N],dis2[N],minim=1000*1000,maxim=0;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>0)
        {
            dis1[i]=a[i]-a[i-1];
            if(dis1[i]>maxim)
                maxim=dis1[i];
        }
            
            
        if(i>1)
        {
            dis2[i]=a[i]-a[i-2];
            if(dis2[i]<minim)
                minim=dis2[i];
        }
            
    }
    cout<<max(minim,maxim)<<endl;
    
        
    
    
    
    
    return 0;
}