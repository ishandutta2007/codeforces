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
        int n;
        string s;
        cin >> n >> s;
        s="$"+s;
        map<array<int,2>,int> m;
        array<int,2> res={-1,n};
        array<int,2> a={0,0};
        m[a]=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='L') a[0]--;
            else if(s[i]=='R') a[0]++;
            else if(s[i]=='D') a[1]--;
            else if(s[i]=='U') a[1]++;
            if(m.find(a)!=m.end()&&i-m[a]<res[1]-res[0]+1) res={m[a]+1,i};
            m[a]=i;
        }
        if(res[0]!=-1) cout << res[0] << " " << res[1] << "\n";
        else cout << "-1\n";
    }
    return 0;
}