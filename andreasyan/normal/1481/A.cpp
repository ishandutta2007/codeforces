#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int px, py;
int n;
char s[N];

void solv()
{
    scanf("%d%d", &px, &py);
    scanf(" %s", s);
    n = strlen(s);
    int minx = 0, maxx = 0;
    int miny = 0, maxy = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'L')
            --minx;
        else if (s[i] == 'R')
            ++maxx;
        else if (s[i] == 'D')
            --miny;
        else
            ++maxy;
    }
    if (minx <= px && px <= maxx && miny <= py && py <= maxy)
        printf("YES\n");
    else
        printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}