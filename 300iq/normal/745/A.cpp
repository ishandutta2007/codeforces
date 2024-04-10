#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    set <string> s;
    string t;
    cin >> t;
    int n = t.size();
    while (n--)
    {
        s.insert(t);
        rotate(t.begin(), t.begin() + 1, t.end());
    }
    cout << s.size() << endl;
}