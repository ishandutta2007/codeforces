#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
void f(int k)
{
    for (int i = 0; i < k; i++)
        cout << "  ";
}

int main()
{
    int n, uk, tb;
    string s;
    cin >> s;
    n = s.length();
    uk = 0;
    tb = 0;
    while (uk < n)
    {

        if (s[uk + 1] == '/')
        {
            f(--tb);
            cout << s[uk] << s[uk+1] << s[uk+2] << s[uk+3] << "\n";
            uk+=4;
        }
        else
        {
            f(tb++);
            cout << s[uk] << s[uk+1] << s[uk+2] << "\n";
            uk+=3;
        }
    }
    return 0;
}