#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
#define INF (1000*1000*1000)
#define N 1100
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,l,a[N];
double maxim;


int main()
{
    cout <<fixed;
    cout <<setprecision(10);
    cin>>n>>l;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    maxim=a[0];
    for(int i=1;i<n;i++)
    {
        if(((double)a[i]-(double)a[i-1])/2>maxim)
            maxim=((double)a[i]-(double)a[i-1])/2;  
    }
    if((double)l-(double)a[n-1]>maxim)
        maxim=(double)l-(double)a[n-1];
    cout<<maxim<<endl;      
    
    
    return 0;
}