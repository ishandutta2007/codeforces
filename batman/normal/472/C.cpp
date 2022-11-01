////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 100*1001
#define ll long long

ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}

ifstream fin("input.txt");
ofstream fout("output.txt");
bool mark[N];
ll n,p[N];
string s[2][N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[0][i]>>s[1][i];
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        int ex=1;
        if(s[0][p[i]]>s[1][p[i]])
            mark[i]=1,ex=0;
            
        if(i>1 && s[mark[i]][p[i]]<s[mark[i-1]][p[i-1]])
        {
            if(s[ex][p[i]]<s[mark[i-1]][p[i-1]])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            mark[i]=ex;
        }   
    }   
    cout<<"YES";    
    return 0;
}