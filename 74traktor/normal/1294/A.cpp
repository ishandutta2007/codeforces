    #include<bits/stdc++.h>

    using namespace std;

    main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #endif // HOME
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t, n, a, b, c;
        cin >> t;
        for (int i = 1; i <= t; ++i) {
            cin >> a >> b >> c >> n;
            int go = 3 * max({a, b, c}) - a - b - c;
            if (go <= n && (n - go) % 3 == 0) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        return 0;
    }