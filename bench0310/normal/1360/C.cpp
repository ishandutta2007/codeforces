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
        cin >> n;
        vector<bool> v(101,0);
        vector<int> cnt(2,0);
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            cnt[x&1]++;
            v[x]=1;
        }
        bool ok=0;
        for(int i=1;i<=99;i++) ok|=(v[i]&&v[i+1]);
        if((cnt[0]%2)==0||ok==1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}