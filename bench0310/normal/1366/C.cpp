#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> v(n,vector<int>(m));
        for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> v[o][i];
        int res=0;
        for(int a=0;a<(n+m-2+1)/2;a++)
        {
            int r=min(a,n-1);
            int c=a-r;
            vector<int> cnt(2,0);
            while(r>=0&&c<m)
            {
                cnt[v[r][c]]++;
                r--;
                c++;
            }
            r=n-1-min(a,n-1);
            c=m-1-(a-min(a,n-1));
            while(r<n&&c>=0)
            {
                cnt[v[r][c]]++;
                r++;
                c--;
            }
            res+=min(cnt[0],cnt[1]);
        }
        cout << res << "\n";
    }
    return 0;
}