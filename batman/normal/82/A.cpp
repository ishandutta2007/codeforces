////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.0 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n;

void output(int x)
{
    switch(x)
    {
        case 1:
            cout<<"Sheldon";
            break;
        case 2:
            cout<<"Leonard";
            break;
        case 3:
            cout<<"Penny";
            break;
        case 4:
            cout<<"Rajesh";
            break;
        case 5:
            cout<<"Howard";
            break;          
    }
}

int main()
{
    cin>>n;
    for(int i=1;;i*=2)
    {
        if(n<=5*i)
        {
            output(ceil((double)n/i));
            return 0;
        }
        n-=5*i;
    }
    return 0;
}