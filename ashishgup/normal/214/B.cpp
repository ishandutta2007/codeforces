#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
vector<int> g[3];

int32_t main()
{
    IOS;
    int n;
    cin>>n;
    int checkzero=0;
    int cursum=0;
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        int num=ch-'0';
        g[num%3].push_back(num);
        checkzero|=(num==0);
        cursum+=num;
        cursum%=3;
    }
    if(!checkzero)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=0;i<=2;i++)
        sort(g[i].rbegin(), g[i].rend());
    if(cursum>0 && g[cursum].size())
        g[cursum].pop_back();
    else if(cursum>0)
    {
        cursum=(cursum==1)?2:1;
        g[cursum].pop_back();
        g[cursum].pop_back();
    }
    string ans="";
    for(int i=0;i<=2;i++)
    {
        for(auto it:g[i])
            ans+=(char)(it+'0');
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());\
    if(ans[0]=='0')
        cout<<"0";
    else
        cout<<ans;
    return 0;
}