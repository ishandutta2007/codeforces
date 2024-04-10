#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> v={-1};
        for(int i=0;i<n;i++) if(s[i]=='1') v.push_back(i);
        v.push_back(n);
        int res=0;
        if(v.size()==2) res=1+((n-1)/(k+1));
        else
        {
            for(int i=0;i<(int)v.size()-1;i++)
            {
                int x=v[i+1]-v[i]-1;
                int c=k;
                if(i==0||i==(int)v.size()-2) c=0;
                res+=max(0,(x-c)/(k+1));
            }
        }
        cout << res << "\n";
    }
    return 0;
}