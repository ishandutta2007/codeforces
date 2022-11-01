//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.1 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n,k,d,ans[N][N];
bool mark;
int main()
{
    cin>>n>>k>>d;
    for(int i=1;i<=d;i++)
        if(tavan(k,i)>1000)
        {
            mark=1;
            break;
        }
    if(!mark)   
    if(tavan(k,d)<n)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            ans[i][j]=1;
    for(int i=0;i<n;i++)
    {
        ans[0][i]+=i;
        for(int j=0;j<d-1 && ans[j][i]>k;j++)
        {
            ll ex=ans[j][i]/k;
            if(ans[j][i]%k==0)
                ex--;
            ans[j][i]%=k;
            if(ans[j][i]==0)
                ans[j][i]=k;
            ans[j+1][i]+=ex;    
        }
    }   
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
        
    return 0;
}