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
        int n,x;
        cin >> n >> x;
        vector<int> c(2,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            c[a&1]++;
        }
        bool ok=0;
        for(int i=0;i<=x;i++) ok|=(c[0]>=i&&c[1]>=x-i&&((x-i)&1));
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}