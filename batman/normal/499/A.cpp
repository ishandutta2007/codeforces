#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N 60
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

int n,x,l[N],r[N],ans;

int main()
{
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
        ans+=r[i]-l[i]+1;
    }
    
    for(int i=0;i<n;i++)
    {
        int q=1;
        if(i==0)
            q=l[i]-1;
        else
            q=l[i]-r[i-1]-1;
        ans+=q%x;       
    }   
    cout<<ans<<endl;;   
    
    
    return 0;
}