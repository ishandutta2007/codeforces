#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x)
{
    for (int y = 2; y < x; y++)
        if (x % y == 0)
            return false;
        
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    set<string> a, b, u;
    
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.insert(s);
    }
    
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        
        if (a.count(s))
        {
            a.erase(s);
            u.insert(s);
        }
        else b.insert(s);
    }
    
    // YES first, NO second
    
    if (u.size() % 2 == 0)
        cout << (a.size() > b.size() ? "YES" : "NO") << endl;
    else
        cout << (a.size() >= b.size() ? "YES" : "NO") << endl;
    
    return 0;
}