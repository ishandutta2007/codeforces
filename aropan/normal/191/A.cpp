#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = (int)1e+9;
const int MAXL = 1024;

int f[26][26];
char s[MAXL];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif
    for (int i = 0; i < 26; i++)
    {
    	for (int j = 0; j < 26; j++)
    		f[i][j] = -INF;
    	f[i][i] = 0;
    }

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
    	scanf("%s", s);
    	int l = strlen(s);
    	char fs = s[0] - 'a';
    	char ls = s[l - 1] - 'a';
    	for (int j = 0; j < 26; j++)
    		f[j][ls] = max(f[j][ls], f[j][fs] + l);
    }

    int ans = -INF;
    for (int i = 0; i < 26; i++)
    	ans = max(ans, f[i][i]);
    printf("%d\n", ans);

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}