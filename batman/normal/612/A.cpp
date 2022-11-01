#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (301*1000)

ll n,p,q;
string s;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p>>q>>s;
    for(int i=0;i*p<=n;i++)
        if((n-i*p)%q==0)
        {
            cout<<i+(n-i*p)/q<<"\n";
            ll pp=0;
            for(int j=0;j<i;j++)
            {
                for(int k=0;k<p;k++)
                    cout<<s[pp++];
                cout<<"\n"; 
            }
            while(pp<n)
            {
                for(int k=0;k<q;k++)
                    cout<<s[pp++];
                cout<<"\n"; 
            }
            return 0;   
        }
    cout<<"-1"; 
    return 0;
}