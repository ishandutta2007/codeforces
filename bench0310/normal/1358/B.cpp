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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(),a.end());
        int res=1;
        int idx=0;
        while(idx<n)
        {
            if(a[idx]<=res)
            {
                res++;
                idx++;
                continue;
            }
            int nxt=idx+1;
            while(nxt<n&&a[nxt]>res+(nxt-idx)) nxt++;
            if(nxt<n)
            {
                res+=(nxt-idx+1);
                idx=nxt+1;
            }
            else break;
        }
        cout << res << "\n";
    }
    return 0;
}