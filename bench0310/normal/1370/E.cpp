#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vector<int> v;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i]) continue;
        if(s[i]=='1') v.push_back(-1);
        else v.push_back(1);
        sum+=v.back();
    }
    if(sum!=0) cout << "-1\n";
    else
    {
        int res=0;
        int now=0;
        for(int x:v)
        {
            now+=x;
            now=max(now,0);
            res=max(res,now);
        }
        now=0;
        for(int x:v)
        {
            now-=x;
            now=max(now,0);
            res=max(res,now);
        }
        cout << res << "\n";
    }
    return 0;
}