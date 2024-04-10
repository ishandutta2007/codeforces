//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.2 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }

string s,t,p;
bool mark;
int main()
{ 
    cin>>s>>t;
    if(s>t)
    {
        cout<<"No such string";
        return 0;
    }
    s[s.size()-1]++;
    for(int i=s.size()-1;i>0;i--)
    {
        if(s[i]>'z')
        {    
            s[i]='a';
            s[i-1]++;
        }
        else
            break;
    } 
    if(s>=t)
    {
        cout<<"No such string";
        return 0;
    }
    
        cout<<s;
    
    return 0;
}