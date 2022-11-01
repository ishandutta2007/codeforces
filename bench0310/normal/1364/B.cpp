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
        vector<int> p(n);
        for(int i=0;i<n;i++) cin >> p[i];
        vector<int> res;
        res.push_back(p[0]);
        int idx=0;
        while(idx+1<n)
        {
            int nxt=idx+1;
            while(nxt+1<n&&(p[idx]<p[idx+1])==(p[nxt]<p[nxt+1])) nxt++;
            res.push_back(p[nxt]);
            idx=nxt;
        }
        cout << res.size() << "\n";
        for(int x:res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}