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
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("milk3.in");
ofstream fout("milk3.out");
    
int main()
{ 
    int n,a,num=1,ans[200];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a==num)
        {
            ans[num]=i+2000;
            num++;
        }
    }
    cout<<num-1<<endl;
    for(int i=1;i<num;i++)
        cout<<ans[i]<<" ";
    return 0;
}