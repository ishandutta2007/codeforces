#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n+1,0);
    vector<int> y(n+1,0);
    for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
    vector<vector<vector<int>>> a(2,vector<vector<int>>(2));
    for(int i=1;i<=n;i++) a[x[i]&1][y[i]&1].push_back(i);
    auto ok=[&]()->bool
    {
        int c=0;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) c+=(!a[i][j].empty());
        return (c>=2);
    };
    while(ok()==0)
    {
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) a[i][j].clear();
        for(int i=1;i<=n;i++)
        {
            x[i]=(x[i]+(x[i]&1))/2;
            y[i]=(y[i]+(y[i]&1))/2;
            a[x[i]&1][y[i]&1].push_back(i);
        }
    }
    int one=(!a[0][0].empty())+(!a[1][1].empty());
    int two=(!a[0][1].empty())+(!a[1][0].empty());
    if(one>0&&two>0)
    {
        cout << a[0][0].size()+a[1][1].size() << "\n";
        for(int b:a[0][0]) cout << b << " ";
        for(int b:a[1][1]) cout << b << " ";
    }
    else if(one>0)
    {
        cout << a[0][0].size() << "\n";
        for(int b:a[0][0]) cout << b << " ";
    }
    else if(two>0)
    {
        cout << a[0][1].size() << "\n";
        for(int b:a[0][1]) cout << b << " ";
    }
    cout << "\n";
    return 0;
}