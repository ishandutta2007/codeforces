#include <bits/stdc++.h>

using namespace std;

#define int int64_t

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int n;
cin >> n;
vector<int> a(1000001, -1), b(1000001, -1);
vector<int> c(1000001), d(1000001);
for(int i = 0; i < n; i++) 
{
int x, y;
cin >> x >> y;
c[i] = x;
d[i] = y;
a[x] = i;
b[y] = i;
}
vector<int> ans(n);
int last = a[0];
for(int i = 0; 2*i + 1 < n; i++)
{
ans[2*i + 1] = d[last];
last = a[d[last]];
}
for(int i = 0; i < 1000001; i++) if(a[i] != -1 && b[i] == -1) last = i;

for(int i = 0; 2*i < n; i++)
{
ans[2*i] = last;
last = d[a[last]];
}
for(int i = 0; i < n; i++)
cout << ans[i] << ' ';
    return 0;
}