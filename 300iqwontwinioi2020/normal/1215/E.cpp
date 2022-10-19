#include <bits/stdc++.h>

using namespace std;

int n;
vector < int > v[22];

long long ans = 0;

main()
{
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[x].push_back (i);
    }
    for (int i = 1; i <= 20; i++)
    for (int j = i + 1; j <= 20; j++){
        long long a = (int)v[i].size(), b = (int)v[j].size();
        long long l = -1;
        long long num = 0;
        for (int r = 0; r < b; r++){
            while (l + 1 < a && v[i][l + 1] < v[j][r])
                l++;
            num += l + 1;
        }
        long long c = a * b;
        if (num > c - num)
            num = c - num;
        ans += num;
    }
    cout << ans << endl;
    return 0;
}