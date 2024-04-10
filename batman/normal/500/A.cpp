#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N (50*1000)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");


int main()
{
    ll n,t,a[N],p=1;
    cin>>n>>t;
    if(t==p)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(p==i)
        {
            p+=a[i];
            if(t==p)
            {
                cout<<"YES"<<endl;
                return 0;
            }
            if(p>t)
            {
                
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
            
        
    
    
    
    return 0;
}