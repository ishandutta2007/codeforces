#include <bits/stdc++.h>

using namespace std;

vector < int > x, y;

main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++){
        if (a[i] < b[i])
            x.push_back(i + 1);
        if (a[i] > b[i])
            y.push_back(i + 1);
    }
    int p = (int)x.size(), q = (int)y.size();
    if ((p + q) % 2 == 1){
        cout << -1 << endl;
        return 0;
    }
    int ans = (p + q) / 2 + p % 2;
    cout << ans << endl;
    for (int i = 0; i + 1 < p; i += 2)
        cout << x[i] << " " << x[i + 1] << endl;
    for (int i = 0; i + 1 < q; i += 2)
        cout << y[i] << " " << y[i + 1] << endl;
    if (p % 2 == 1){
        cout << x[p - 1] << " " << x[p - 1] << endl;
        cout << x[p - 1] << " " << y[q - 1] << endl;
    }
    return 0;
}