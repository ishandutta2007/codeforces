#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
string s;

int32_t main()
{
    IOS; 
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            reverse(s.begin(), s.begin()+i);
        }
    }
    cout<<s;
    return 0;   
}