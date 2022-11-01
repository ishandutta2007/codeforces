
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
#define PB push_back
#define IB ios_base::sync_with_stdio(0);
const ll MOD=1e9+7;
ll tavan(ll a,ll b){return b?(tavan(a*a,b>>1) * (b & 1?a:1)):1;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
bool isprime(int x){for(int i=2;i<=sqrt(x);i++)if(!(x%i))return false;return true;}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("hamming.in");
ofstream fout("hamming.out");
ll a[26],ans,sum;
map <ll,ll> m[26];
string s;
int Sa1378
{ 
    
    for(int i=0;i<26;i++)
        cin>>a[i];
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        ans+=m[s[i]-'a'][sum];
        sum+=a[s[i]-'a'];
        m[s[i]-'a'][sum]++; 
    }
    cout<<ans<<endl;    
    return 0;
}