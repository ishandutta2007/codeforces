#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'A']++;
    int mi = 1000000000;
    for (int i = 0; i < k; i++)
        mi = min(cnt[i], mi);
    cout << mi * k;
}