#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int bpow(int x, int n, int m)
{
if(n == 0) return 1;
int t = bpow(x, n/2, m);
if(n % 2) return x * t * t % m;
else return t * t % m;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
int a, b;
cin >> s >> a >> b;
if(s[0] == 0)
{
cout << "NO\n";
return 0;
}
int n = s.size();
vector<int> pref(n);
int cur = 0;
for(int i = 0; i < n; i++)
{
cur = cur * 10 + s[i] - '0';
cur %= a;
pref[i] = cur;
}
cur = 0;
for(int i = 0; i < n - 1; i++)
{
cur = cur + (s[n - i - 1] - '0')*bpow(10, i, b);
cur %= b;
if(cur == 0 && s[n - i - 1] != '0' && pref[n - i - 2] == 0)
{
cout << "YES\n" << s.substr(0, n - i - 1) << "\n" << s.substr(n - i - 1) << "\n";
return 0;
}
}
cout << "NO\n";
    return 0;
}