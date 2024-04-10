    #include <bits/stdc++.h>
    using namespace std;
    const int N = 100005;

    int n, m;
    int a[N];

    int main()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        long long sum = 0;
        int vz = 0;
        int maxu = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum += a[i];
            if (a[i])
                ++vz;
            maxu = max(maxu, a[i]);
        }
        sum -= vz;
        int u = 0;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] > u)
            {
                ++u;
            }
        }
        sum -= max(0, maxu - u);
        cout << sum << endl;
        return 0;
    }