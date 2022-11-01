////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1 //////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N 1100
#define ll long long
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("milk3.in");
ofstream fout("milk3.out");


string s;
ll a,a2,q,res;

void dp(int x)
{
    if(x==q)
    {
        if(a2==a)
            res++;
        return ;        
    }
    a2++;
    dp(x+1);
    a2-=2;
    dp(x+1);
    a2++;
}

int main()
{ 
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='+')
            a++;
        else
            a--;    
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='+')
            a--;
        else if(s[i]=='-')
            a++;    
        else
            q++;
    dp(0);      
    long double ans=(double)res/tavan(2,q);
    cout<<setprecision(12)<<fixed<<ans<<endl;           
    return 0;
}