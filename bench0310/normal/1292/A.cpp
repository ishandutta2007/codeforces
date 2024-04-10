#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<vector<int>> v(3,vector<int>(n+1,-1));
    int now=0;
    while(q--)
    {
        int r,c;
        cin >> r >> c;
        v[r][c]=-v[r][c];
        for(int i=max(1,c-1);i<=min(n,c+1);i++) if(v[3-r][i]==1) now+=v[r][c];
        if(now==0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}