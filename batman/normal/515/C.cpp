//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.1 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (100*1001)
#define ll long long
#define ld long double
#define ST setprecision
#define MOD (ll)1e9+7
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n;
string s;
vector <ll> v;
int main()
{ 
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        switch(s[i]-48)
        {
            case 9:
                v.push_back(7),v.push_back(3),v.push_back(2),v.push_back(3);
                break;
            case 8:
                v.push_back(7),v.push_back(2),v.push_back(2),v.push_back(2);
                break;  
            case 7:
                v.push_back(7);
                break;  
            case 6:
                v.push_back(5),v.push_back(3);
                break;  
            case 5:
                v.push_back(5);
                break;  
            case 4:
                v.push_back(2),v.push_back(2),v.push_back(3);
                break;  
            case 3:
                v.push_back(3);
                break;  
            case 2:
                v.push_back(2);
                break;  
                
        }
    }   
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)
        cout<<v[i];
        
    return 0;
}