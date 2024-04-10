#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1000*1000)
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,deg[N],s[N],m;
queue <ll> q;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>deg[i]>>s[i];
        if(deg[i]==1)
            q.push(i);
        m+=deg[i];  
    }
    cout<<m/2<<endl;
    while(q.empty()==0)
    {
        int x=q.front();
        q.pop();
        if(deg[x]==1)
        {
            cout<<x<<" "<<s[x]<<endl;
        deg[s[x]]--;
        if(deg[s[x]]==1)
            q.push(s[x]);
        s[s[x]]^=x;
        deg[x]--;
        }
                
            
    }
    
    return 0;
}