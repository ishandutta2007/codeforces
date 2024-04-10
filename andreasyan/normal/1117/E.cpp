#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 10004;

int n;
char a[N];

vector<string> v;

char s[3][N], f[3][N];

char ans[N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHIN
    scanf(" %s", a);
    n = strlen(a);
    for (char i = 'a'; i <= 'z'; ++i)
    {
        for (char j = 'a'; j <= 'z'; ++j)
        {
            for (char k = 'a'; k <= 'z'; ++k)
            {
                string s = "";
                s += i;
                s += j;
                s += k;
                v.push_back(s);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        s[0][i] = v[i][0];
        s[1][i] = v[i][1];
        s[2][i] = v[i][2];
    }
    for (int i = 0; i < 3; ++i)
    {
        printf("? %s\n", s[i]);
        fflush(stdout);
        scanf(" %s", f[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        int u = (f[0][i] - 'a') * 26 * 26 + (f[1][i] - 'a') * 26 + (f[2][i] - 'a');
        ans[u] = a[i];
    }
    printf("! %s\n", ans);
    fflush(stdout);
    return 0;
}