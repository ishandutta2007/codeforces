#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n--)
    {
        string s,t;
        cin >> s >> t;
        s+='?';
        t+='?';
        vector<pair<char,int>> a,b;
        int cnt=1;
        for(int i=1;i<(int)s.size();i++)
        {
            if(s[i]!=s[i-1])
            {
                a.push_back({s[i-1],cnt});
                cnt=1;
            }
            else cnt++;
        }
        cnt=1;
        for(int i=1;i<(int)t.size();i++)
        {
            if(t[i]!=t[i-1])
            {
                b.push_back({t[i-1],cnt});
                cnt=1;
            }
            else cnt++;
        }
        bool res=1;
        if(a.size()!=b.size()) res=0;
        for(int i=0;i<(int)min(a.size(),b.size());i++)
        {
            if(a[i].first!=b[i].first||a[i].second>b[i].second) res=0;
        }
        if(res) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}