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
#define N (200*1000)
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
//bool sortt(int x,int y){ return a[x] < a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");
string s;
int n;
int Sa1378
{
    IB
    cin>>n;
    getline(cin,s);
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        int f=0,r=0;
        if(s[0]=='m' && s[1]=='i' && s[2]=='a' && s[3]=='o' && s[4]=='.')
            r=1;

        if(s[s.size()-1]=='.' && s[s.size()-2]=='a' && s[s.size()-3]=='l' && s[s.size()-4]=='a' && s[s.size()-5]=='l')
            f=1;

        if((r && f) || (!r && !f))
            cout<<"OMG>.< I don't know!\n";
        else if(r)
            cout<<"Rainbow's\n";
        else if(f)
            cout<<"Freda's\n";      
    }
                            
    return 0;
}