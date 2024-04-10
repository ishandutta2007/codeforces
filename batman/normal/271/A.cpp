////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.0 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long
#define DELTA 1000
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");


int a;

bool check(int x)
{
    int xt[4]={},p=0;
    while(x)
    {
        for(int i=0;i<p;i++)
            if(x%10==xt[i])
                return false;
        xt[p]=x%10;
        p++;
        x/=10;
                
    }
    return true;
}
int main()
{
    cin>>a;
    
    for(int i=a+1;;i++)
    {
        if(check(i)==true)
        {
            cout<<i;
            return 0;
        }
    }   
    return 0;
}