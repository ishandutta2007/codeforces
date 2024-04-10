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



ll n,p;
string s[1100],s2[1100],a,b;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int q=0;
        cin>>a>>b;
        for(int i=0;i<p;i++)
        {
            if(s2[i]==a)
            {
                s2[i]=b;
                q++;
            }
        }
        if(q==0)
        {
            s[p]=a;
            s2[p]=b;
            p++;
        }
    }
    cout<<p<<endl;
    for(int i=0;i<p;i++)
    {
        cout<<s[i]<<" "<<s2[i]<<endl;
    }
    
    return 0;
}