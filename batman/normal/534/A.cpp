//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.2 ///////////////////
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
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
int n,p;
int Sa1378
{ 
    cin>>n;
    if(n==1)
    {
        cout<<1<<endl<<1;
        return 0;
    }
    if(n==2)
    {
        cout<<1<<endl<<1;
        return 0;
    }
    if(n==3)
    {
        cout<<2<<endl<<1<<" "<<3;
        return 0;
    }
    if(n==4)
    {
        cout<<4<<endl<<"2 4 1 3";
        return 0;
    }
    cout<<n<<endl;
    for(int i=1;i<=(n-1+(n%2));i+=2)
        cout<<i<<" ";
    for(int i=2;i<=(n+1-(n%2));i+=2)
        cout<<i<<" ";
            
    
    return 0;
}