#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll>> vvll;

#define PI 3.141592653589793
#define MOD 1000000007

ll gcd(int a, int b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    vector<ll> v(n+1);
    ll mint=0;
    v[0]=0;
    vector<bool> visited(n+1,false);
    vector<ll> v2;
    for(ll i=1;i<n+1;i++)
    {
        cin>>v[i];
        if(v[i]==i)
        {
            visited[i]=true;
        }
    }
    ll size=0;
    bool check=true;
    for(ll i=1;i<=n;i++)
    {
        if(visited[i]==true)
        {
            continue;
        }
        ll count=0;
        ll j=i;
        visited[i]=true;
        while(v[j]!=i&&v[j]!=j&&visited[v[j]]==false)
        {
            j=v[j];
            count++;
            visited[j]=true;
        }
        if(v[j]!=i)
        {
            check=false;
            break;
        }
        if(count%2==0)
        {
            v2.push_back(count+1);
        }
        else
        {
            v2.push_back((count+1)/2);
        }
        size++;
        if(count>mint)
        {
            mint=count;
        }
    }
    if(check==false)
    {
        cout<<"-1";
    }
    else
    {
        if(size>0)
        {
            ll ans=v2[0];
            for(ll i=0;i<size;i++)
            {
                ans=(ans*v2[i])/gcd(ans,v2[i]);
            }
            cout<<ans;
        }
        else
        {
            cout<<"1";
        }
    }
    return 0;
}