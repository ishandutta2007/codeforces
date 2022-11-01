////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
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

int n,t;
string s;
int main()
{
    cin>>n>>t>>s;       
    for(int i=0;i<t;i++)
        for(int j=n-1;j>0;j--)
            if(s[j]=='G' && s[j-1]=='B')
                s[j]='B',s[j-1]='G',j--;
    cout<<s;
    
    return 0;
}