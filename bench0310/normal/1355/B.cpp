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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(),v.end());
        int idx=0;
        int now=0;
        int res=0;
        while(idx<n)
        {
            while(idx<n&&(idx==0||now<v[idx-1]))
            {
                idx++;
                now++;
            }
            if(now==v[idx-1])
            {
                res++;
                now=0;
            }
        }
        cout << res << "\n";
    }
    return 0;
}