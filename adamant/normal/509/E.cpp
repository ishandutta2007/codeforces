#include <bits/stdc++.h>

using namespace std;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> vowel{{'I', 1}, {'E', 1}, {'A', 1}, {'O', 1}, {'U', 1}, {'Y', 1}};
    int n = s.size();
    double ans = 0;

    double sum1[n + 1], sum2[n + 2];
    sum1[1] = 1;
    for(int j = 2; j <= n; j++)
        sum1[j] = sum1[j - 1] + 1. / j;
    sum2[n + 1] = 0;
    for(int j = n; j > 0; j--)
        sum2[j] = sum2[j + 1] + 1. * (n - j + 1) / j;

    for(int i = 0; i < n; i++)
        if(vowel[s[i]])
        {
            int k = min(i + 1, n - i);
            ans += k * (1 + sum1[n - k + 1] - sum1[k]) + sum2[n - k + 2];
        }
    cout << fixed << setprecision(7) << ans << "\n";
}