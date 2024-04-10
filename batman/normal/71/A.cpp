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


int main()
{
    int n;
    string s;
    cin>>n; 
    for(int i=0;i<n;i++)
    {
        cin>>s;
        if(s.size()<=10)
            cout<<s<<endl;
        else
            cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
    }
    
    
    return 0;
}