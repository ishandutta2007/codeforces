#include <bits/stdc++.h>

using namespace std;

vector<int> a;

pair<int, int> f(int x)
{
    for (int i = 0; i < 10; i++)
        x = a[x];
    
    return x < a[x] ? make_pair(x, a[x]) : make_pair(a[x], x);
}

int main()
{
    int n;
    cin >> n;
    
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    
    set<pair<int, int>> d;
    for (int x: a)
        d.insert(f(x));
    
    cout << d.size() << endl;
    
    return 0;
}