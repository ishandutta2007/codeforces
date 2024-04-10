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
#define N (5555)
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
ifstream fin("input.txt");
ofstream fout("output.txt");
string s;
bool mark[50];
int ans;
int Sa1378
{
    getline(cin,s);
    for(int i=0;i<s.size();i++)
        if(s[i]>='a' && s[i]<='z')
            mark[s[i]-'a']=true;
    for(int i=0;i<26;i++)
        if(mark[i])
            ans++;
    cout<<ans;
    return 0;
}