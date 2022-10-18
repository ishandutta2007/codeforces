#include <bits/stdc++.h>

using namespace std;

#define int int64_t

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int n;
cin >> n;
vector<int> a, b, c;
for(int i = 0; i < n; i++)
{
int t;
cin >> t;
if(t == 1) a.push_back(i + 1);
if(t == 2) b.push_back(i + 1);
if(t == 3) c.push_back(i + 1);
}
if(a.size() < b.size()) swap(a, b);
if(b.size() < c.size()) swap(b, c);
if(a.size() < b.size()) swap(a, b);
cout << c.size() << endl;
for(int i = 0; i < c.size(); i++)
cout << c[i] << ' ' << b[i] << ' ' << a[i] << endl;

    return 0;
}