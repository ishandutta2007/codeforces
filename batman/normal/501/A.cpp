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



ll a,b,c,d;

int main()
{
    cin>>a>>b>>c>>d;
    double k1=max((double)3*a/10,(double)a-a*c/250);
    double k2=max((double)3*b/10,(double)b-b*d/250);
    if(k1>k2)
        cout<<"Misha";
    else if(k1<k2)
        cout<<"Vasya";
    else
        cout<<"Tie";        
    
    
    return 0;
}