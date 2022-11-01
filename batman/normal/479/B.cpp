#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N 1100
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

int n,k,a[N],s,m,ans1[N],ans2[N];




int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    for(int i=0;;i++)
    {
        int p1,p2,maxim=0,minim=INF;
        for(int i=0;i<n;i++)
            if(a[i]>maxim)
            {
                maxim=a[i];
                p1=i;
            }
        for(int i=0;i<n;i++)
            if(a[i]<minim)
            {
                minim=a[i];
                p2=i;
            }    
    
        s=a[p1]-a[p2];
        if(s==0)
            break;
        if(i==k)
            break;  
        m=i+1;
        ans1[i]=p1+1;
        ans2[i]=p2+1;
        a[p1]--;
        a[p2]++;    
    }   
    cout<<s<<" "<<m<<endl;
    for(int i=0;i<m;i++)
        cout<<ans1[i]<<" "<<ans2[i]<<endl;
    
    return 0;
}