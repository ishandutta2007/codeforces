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
 
const int N=1e6+5;

int n, a, b;
string s;

int32_t main()
{
    IOS;
    cin>>n>>a>>b>>s;
    int ans=0;
    char prev='*';
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*')
            prev='*';
        else 
        {
            if(prev=='*')
            {
                if(a>=b && a>0)
                {
                    a--;
                    ans++;
                    prev='a';
                }
                else if(b>0)
                {
                    b--;
                    ans++;
                    prev='b';
                }
            }
            else if(prev=='a')
            {
                if(b>0)
                {
                    b--;
                    ans++;
                    prev='b';
                }
                else
                {
                    prev='*';
                }
            }
            else
            {
                if(a>0)
                {
                    a--;
                    ans++;
                    prev='a';
                }
                else
                {
                    prev='*';
                }
            }
        }
    }
    cout<<ans;
    return 0;
}