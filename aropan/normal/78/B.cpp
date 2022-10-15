#include <cstdio>

using namespace std;

const int MAXN = 1001;
const char c[8] = "ROYGBIV";

int n;
char s[MAXN];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    scanf("%d", &n);
    for (int i = 0; i < 7; i++)
        s[i] = c[i];

    for (int i = 7; i < n; i++)
        s[i] = s[i - 4];

    s[n] = 0;
    puts(s);

    return 0;
}