#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF (1000*1000*1000)
#define N 101*1000
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,r,avg,a[N],b[N],index[N],sum,ans;

bool ess(ll x1,ll x2)
{
    return b[x1]<b[x2];
}

int main()
{
    
    cin>>n>>r>>avg;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=a[i];
        index[i]=i;
    }
    sort(index,index+n,ess);
    //for(int i=0;i<n;i++)
        //cerr<<index[i]<<" ";
    //cout<<endl;   
    for(int i=0;sum<avg*n;i++)
    {
        int ex=min(r-a[index[i]],avg*n-sum);
        sum+=ex;
        a[index[i]]+=ex;
        ans+=ex*b[index[i]];   
    }
    cout<<ans;  
        
    return 0;
}