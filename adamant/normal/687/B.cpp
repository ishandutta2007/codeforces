#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int c[n];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    vector<int> pr;
    for(int i = 2; i * i <= k; i++)
    {
        if(k % i == 0)
        {
            int t = 1;
            while(k % i == 0)
            {
                k /= i;
                t *= i;
            }
            pr.push_back(t);
        }
    }
    if(k != 1)
        pr.push_back(k);
    for(auto it: pr)
    {
        for(int i = 0; i < n; i++)
        {
            if(c[i] % it == 0)
                goto nxt;
        }
        cout << "No\n";
        return 0;
        nxt:;
    }
    cout << "Yes\n";
	return 0;
}