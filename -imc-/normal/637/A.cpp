#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    int ans = 0;
    map<int, int> lol;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        lol[t]++;
        if(lol[t] > mx)
        {
            mx = lol[t];
            ans = t;
        }
    }
    cout << ans << "\n";
}