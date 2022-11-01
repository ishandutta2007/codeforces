#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int inf=(1<<30);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<set<int>> v(4);
        for(int i=1;i<=3;i++) v[i].insert(inf);
        for(int i=0;i<(int)s.size();i++) v[s[i]-'0'].insert(i);
        int res=inf;
        for(int i=0;i<(int)s.size();i++)
        {
            int x=0;
            for(int j=1;j<=3;j++) x=max(x,*v[j].lower_bound(i));
            if(x!=inf) res=min(res,x-i+1);
        }
        if(res!=inf) cout << res << "\n";
        else cout << "0\n";
    }
    return 0;
}