#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


const int MAXN = 10007;

int n, m;
string a[MAXN];
string s;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < 4 * n; i++)
    {
        getline(cin, s);
        reverse(s.begin(), s.end());

        a[i] = "";
        int k = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') k++;
            if (k == m)
            {
                a[i] = s.substr(0, j + 1);
                break;
            }
        }
        if (a[i] == "")
        {
            puts("NO");
            return 0;
        }
    }

    bool f;

    f = true;
    for (int i = 0; i < 4 * n; i += 4)
        f &= a[i + 0] == a[i + 1] && a[i + 1] == a[i + 2] && a[i + 2] == a[i + 3];
    if (f) { puts("aaaa"); return 0; }

    f = true;
    for (int i = 0; i < 4 * n; i += 4)
        f &= a[i + 0] == a[i + 1] && a[i + 2] == a[i + 3];
    if (f) { puts("aabb"); return 0; }

    f = true;
    for (int i = 0; i < 4 * n; i += 4)
        f &= a[i + 0] == a[i + 2] && a[i + 1] == a[i + 3];
    if (f) { puts("abab"); return 0; }

    f = true;
    for (int i = 0; i < 4 * n; i += 4)
        f &= a[i + 0] == a[i + 3] && a[i + 1] == a[i + 2];
    if (f) { puts("abba"); return 0; }

    puts("NO");
    return 0;
}