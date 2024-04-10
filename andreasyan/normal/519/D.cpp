#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int a[26];
int n;
char b[N];
long long p[N];

map<long long, int> mp[26];
int main()
{
    for (int i = 0; i < 26; ++i)
        cin >> a[i];
    cin >> b;
    n = strlen(b);
    for (int i = 0; i < n; ++i)
    {
        if (i)
            p[i] = p[i - 1];
        p[i] += a[b[i] - 'a'];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i)
            ans += mp[b[i] - 'a'][p[i - 1]];
        mp[b[i] - 'a'][p[i]]++;
    }
    cout << ans << endl;
    return 0;
}