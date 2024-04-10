#include <bits/stdc++.h>

using namespace std;

const long long N = 4e5 + 5, MOD = 998244353;

long long n;
long long a, b;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin>>n>>s;
    s = "#" + s;
    a = 1;
    b = n;
    while (a < n && s[a + 1] == s[1])
        a++;
    while (b > 1 && s[b - 1] == s[n])
        b--;
    if (s[1] != s[n])
        cout<<a + n - b + 2<<endl;
    else
        cout<<(a + 1) * (n - b + 2) % MOD<<endl;
    return 0;
}