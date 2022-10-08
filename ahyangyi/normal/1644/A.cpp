#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        bool r = false, g = false, b = false, ok = true;
        for (char c : s)
        {
            switch (c)
            {
                case 'r':
                    r = true;
                    break;
                case 'g':
                    g = true;
                    break;
                case 'b':
                    b = true;
                    break;
                case 'R':
                    if (!r)
                    {
                        ok = false;
                    }
                    break;
                case 'G':
                    if (!g)
                    {
                        ok = false;
                    }
                    break;
                case 'B':
                    if (!b)
                    {
                        ok = false;
                    }
                    break;
            }
        }

        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}