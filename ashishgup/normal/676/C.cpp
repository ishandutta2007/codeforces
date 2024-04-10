#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;
string s;

int work(char ch)
{
    int l=0, cur=0, ans=0;
    for(int r=0;r<n;r++)
    {
        cur+=(s[r]!=ch);
        while(cur>k)
        {
            cur-=(s[l]!=ch);
            l++;
        }
        ans=max(ans, r-l+1);
    }
    return ans;
}

int32_t main()
{
    IOS;
    cin>>n>>k>>s;
    int ans=max(work('a'), work('b'));
    cout<<ans;
    return 0; 
}