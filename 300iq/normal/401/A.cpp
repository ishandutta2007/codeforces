    #include <bits/stdc++.h>

    using namespace std;

    int ans, sum, x, n, q;

    int main()

    {
        scanf("%d %d", &n, &x);
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>q;
            sum += q;
        }
        sum = abs(sum);
        ans = sum / x;
        if (sum % x != 0) ans++;
        cout<<ans<<endl;
    }