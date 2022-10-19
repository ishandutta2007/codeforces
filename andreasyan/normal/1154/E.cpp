#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, k;
int a[N];

char ans[N];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[x] = i;
    }
    set<int> s;
    for (int i = 1; i <= n; ++i)
        s.insert(i);
    char z = '1';
    for (int j = n; j >= 1; --j)
    {
        int i = a[j];
        if (s.find(i) == s.end())
            continue;
        vector<int> v;
        int ii;
        set<int>::iterator it;
        for (it = ++s.find(i), ii = 0; it != s.end() && ii < k; ++it, ++ii)
            v.push_back(*it);
        for (it = --s.find(i), ii = 0; it != s.end() && ii < k; --it, ++ii)
            v.push_back(*it);
        v.push_back(i);
        for (int i = 0; i < v.size(); ++i)
        {
            ans[v[i] - 1] = z;
            s.erase(v[i]);
        }
        if (z == '1')
            z = '2';
        else
            z = '1';
    }
    cout << ans << endl;
    return 0;
}