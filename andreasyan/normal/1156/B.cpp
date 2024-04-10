#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int q[N];

void solv()
{
    memset(q, 0, sizeof q);
    cin >> a;
    n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        q[a[i] - 'a']++;
    }
    int qq = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (q[i])
            ++qq;
    }

    if (qq <= 3)
    {
        vector<int> v;
        for (int i = 0; i < 26; ++i)
            if (q[i])
                v.push_back(i);
        do
        {
            bool z = false;
            for (int i = 0; i < v.size() - 1; ++i)
            {
                if (abs(v[i] - v[i + 1]) == 1)
                {
                    z = true;
                    break;
                }
            }
            if (!z)
            {
                for (int i = 0; i < v.size(); ++i)
                {
                    while (q[v[i]]--)
                        cout << (char)(v[i] + 'a');
                }
                cout << endl;
                return;
            }
        } while (next_permutation(v.begin(), v.end()));
        cout << "No answer" << endl;
        return;
    }
    int z = 0;
    for (int i = 25; i >= 0; --i)
    {
        if (q[i] == 0)
            continue;
        ++z;
        if (z % 2 == 1)
            continue;
        while (q[i]--)
            cout << (char)(i + 'a');
    }
    z = 0;
    for (int i = 25; i >= 0; --i)
    {
        if (q[i] == 0)
            continue;
        ++z;
        if (z % 2 == 0)
            continue;
        while (q[i]--)
            cout << (char)(i + 'a');
    }
    cout << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}