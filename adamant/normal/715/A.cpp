#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int t = 2;
    for(int i = 1; i <= n; i++)
    {
        int mx = 1;
        for(int j = 1; j * j <= i; j++)
            if(i % (j * j) == 0)
                mx = max(mx, j);
        int j = i / mx;
        //[j * (i + 1)]^2 = i * (t + k)
        int G = (i + 1) * (i + 1) * i / mx / mx;
        cout << G - t << "\n";
        t = j;
        //i * (t + k) = [(i + 1) * j]^2
    }
	return 0;
}