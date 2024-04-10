//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2.2 /////////////////
////////////////////////////////////////////////////////////////


// Yesterday is history...
// Tomorrow is a mystery...
// But Today is a GIFT.


#include <bits/stdc++.h>
using namespace std;
#define Sa1378 main()
#define chie(x) cerr << #x << " is " << x << endl;
#define INF 1e9
#define N (110)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
const ll HASH=1e16+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(ll x){for(ll i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(ll x,ll y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
ll n;
char ans[N][N],s[N][N];
int Sa1378
{ 
    IB
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>s[i][j];   
    for(int i=0;i<2*n-1;i++)
        for(int j=0;j<2*n-1;j++)
            ans[i][j]='x';  
    ans[n-1][n-1]='o';      
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(s[i][j]=='o')
                for(int p=0;p<n;p++)
                    for(int q=0;q<n;q++)
                        if(s[p][q]=='.')
                            ans[p-i+n-1][q-j+n-1]='.';
                    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(s[i][j]=='x')
            {
                bool mark=0;
                for(int p=0;p<n;p++)
                    for(int q=0;q<n;q++)
                        if(s[p][q]=='o' && ans[n+i-p-1][n+j-q-1]=='x')
                        {
                            mark=1;
                            break;
                        }
                            
                if(!mark)
                {
                    cout<<"NO";
                    return 0;
                }           
            }
                
    cout<<"YES\n";
    for(int i=0;i<2*n-1;i++)
    {
        for(int j=0;j<2*n-1;j++)
            cout<<ans[i][j];
        cout<<"\n"; 
    }       
    return 0;
}