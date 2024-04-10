#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[1000000];
int le[1000];

int main()
{
    int n, p;
    string s;
    cin >> n >> p;
    cin >> s;
    bool er = false;
    int pos = -1;
    int lett = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        fill(le, le + 1000, 0);
        if (i - 1 >= 0) le[s[i - 1]] = 1;
        if (i - 2 >= 0) le[s[i - 2]] = 1;
        //if (i + 1 < n)  le[s[i + 1]] = 1;
        //if (i + 2 < n)  le[s[i + 2]] = 1;
        for (int j = (int)s[i] + 1; j < (int)('a') + p; j++)
            if ((!le[j]) && (!er))
                pos = i, er = true, lett = j;
    }
    if(pos == -1)
    {
        cout << "NO";
    }
    else
    {
        //cout << pos << endl;
        for (int i = 0; i < pos; i++)
            cout << s[i];
        int tmp = 0;
        cout << (char)lett;
        //if (pos - 1 >= 0)
            if (s[pos - 1] != 'a' && ((char)lett != 'a') && ((char)lett != 'b'))
                for (int i = pos + 1; i < n; i++)
                    {cout << (char)('a' + tmp); tmp = (tmp + 1) % 3;}
            else if (s[pos - 1] != 'b' && (char)lett != 'b')
            {
                tmp = 1;
                for (int i = pos + 1; i < n; i++)
                    {cout << (char)('a' + tmp); tmp = (tmp + 2) % 3;}
            }
            else
            {
                tmp = 0;
                for (int i = pos + 1; i < n; i++)
                {
                    cout << (char)('a' + tmp); tmp = (tmp + 2) % 3;
                }
            }
    }
    return 0;
}