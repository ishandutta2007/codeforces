#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=2e5+5;

int n, k, odd=1, even=2, ans=0;
vector<int> v[N];

int generate_set(int i)
{
    for(int j=1;j<=3;j++)
    {
        v[i].push_back(odd);
        ans=max(ans, odd);
        odd+=2;
    }
    int check=0;
    while(!check)
    {
        int curcheck=1;
        for(auto it:v[i])
        {
            if(gcd(it, even)!=1)
                curcheck=0;
        }
        if(curcheck)
        {
            check=1;
            v[i].push_back(even);
            ans=max(ans, even);
        }
        even+=2;
    }
}

int32_t main()
{
    IOS;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        generate_set(i);
    cout<<ans*k<<endl;
    for(int i=1;i<=n;i++)
    {
        for(auto it:v[i])
            cout<<it*k<<" ";
        cout<<endl;
    }
    return 0;
}