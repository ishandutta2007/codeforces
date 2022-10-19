#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 5003;

int n, m;
string a, b;

char minu[N];

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> a >> b;
        n = a.size();
        m = b.size();
        minu[n] = 'Z';
        for (int i = n - 1; i >= 0; --i)
        {
            minu[i] = min(minu[i + 1], a[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > minu[i])
            {
                for (int j = n - 1; j >= 0; --j)
                {
                    if (a[j] == minu[i])
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (a < b)
            cout << a << endl;
        else
            cout << "---" << endl;
    }
    return 0;
}