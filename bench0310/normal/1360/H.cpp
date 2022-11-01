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
        int n,m;
        cin >> n >> m;
        vector<ll> v(n);
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            v[i]=stoll(s,0,2);
        }
        sort(v.begin(),v.end());
        ll cnt=(1ll<<m)-n;
        int idx=0;
        ll now=(cnt-1)/2;
        while(idx<n&&v[idx]<=now)
        {
            now++;
            idx++;
        }
        string res;
        for(int i=0;i<m;i++)
        {
            res+=((now&1)+'0');
            now/=2;
        }
        reverse(res.begin(),res.end());
        cout << res << "\n";
    }
    return 0;
}