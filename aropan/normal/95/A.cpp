#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 111;

int n;
int f[MAXN];
string a[MAXN];
string s;
int d[MAXN];
char ch, c;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
    cin >> c;

    if (c >= 'a') c -= (int)'a' - (int)'A';
    ch = c == 'A'? 'B' : 'A';


    for (int i = 0; i < (int)s.size(); i++)
    {
        d[i] = s[i] >= 'a';
        if (d[i]) s[i] -= (int)'a' - (int)'A';
    }


    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < (int)a[i].size(); k++)
            if (a[i][k] >= 'a')
                a[i][k] -= (int)'a' - (int)'A';

        for (int j = 0; j < (int)s.size() - (int)a[i].size() + 1; j++)
            if (s.substr(j, a[i].size()) == a[i])
                for (int k = 0; k < (int)a[i].size(); k++)
                    f[k + j] = true;
    }


    for (int i = 0; i < (int)s.size(); i++)
    {
        if (!f[i]) continue;
        s[i] = s[i] == c? ch : c;
    }

    for (int i = 0; i < (int)s.size(); i++)
        if (d[i]) s[i] += (int)'a' - (int)'A';

    cout << s << endl;
    return 0;
}