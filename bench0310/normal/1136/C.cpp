#include <bits/stdc++.h>

using namespace std;

bool in(int r,int c,int n,int m)
{
    if(r<0||c<0||r>=n||c>=m) return 0;
    else return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> a[o][i];
    int b[n][m];
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) cin >> b[o][i];
    bool res=1;
    for(int j=0;j<=n+m-2;j++)
    {
        vector<int> x,y;
        for(int o=0;o<=j;o++)
        {
            int i=j-o;
            if(!in(o,i,n,m)) continue;
            x.push_back(a[o][i]);
            y.push_back(b[o][i]);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(x!=y)
        {
            res=0;
            break;
        }
    }
    if(res) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}