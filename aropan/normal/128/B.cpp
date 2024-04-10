#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <queue>

using namespace std;

#define FS first
#define SC second


typedef unsigned long long mlong;
typedef pair <mlong, mlong> mpair;

struct substring
{
    int FS, SC;
    substring(int l = 0, int r = 0) : FS(l), SC(r) { }
};


const int MAXN = 100007;

mpair p[MAXN];
mpair h[MAXN];

mpair operator*(const mpair &a, const mpair &b) { return make_pair(a.FS * b.FS, a.SC * b.SC); }
mpair operator*(const mpair &a, const long long x) { return make_pair(a.FS * x, a.SC * x); }
mpair operator+(const mpair &a, const mpair &b) { return make_pair(a.FS + b.FS, a.SC + b.SC); }
mpair operator-(const mpair &a, const mpair &b) { return make_pair(a.FS - b.FS, a.SC - b.SC); }

char s[MAXN];
int n, k;

priority_queue <substring> H;


int write(const substring &a)
{
    printf("%d %d: ", a.FS, a.SC);
    for (int i = a.FS; i <= a.SC; i++)
        printf("%c", s[i]);
    printf("\n");
}

inline bool equalsubstring(const substring &a, const substring &b)
{
    if (a.FS > b.FS) return equalsubstring(b, a);
    return h[b.SC] - h[b.FS - 1] == (h[a.SC] - h[a.FS - 1]) * p[b.FS - a.FS];
}

int LCP(const substring &a, const substring &b)
{
    int
        ll = 0,
        rr = min(a.SC - a.FS + 1, b.SC - b.FS + 1);

    while (ll < rr)
    {
        int
            cc = (ll + rr + 1) / 2;
        if (equalsubstring(substring(a.FS, a.FS + cc - 1), substring(b.FS, b.FS + cc - 1)))
            ll = cc;
        else
            rr = cc - 1;
    }
    return ll;
}

bool cmpsubstring(const substring &a, const substring &b)
{
    int lcp = LCP(a, b);
/*
    write(a);
    write(b);
    printf("%d %d\n", lcp, a.SC < a.FS + lcp || b.FS + lcp <= b.SC && s[a.FS + lcp] < s[b.FS + lcp]);
    printf("\n");
//*/
    return a.SC < a.FS + lcp || b.FS + lcp <= b.SC && s[a.FS + lcp] < s[b.FS + lcp];
}

bool operator < (const substring &a, const substring &b)
{
    return !cmpsubstring(a, b);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif

    h[0] = make_pair(0, 0);
    p[0] = make_pair(1, 1);
    gets(s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * make_pair(37, 56);
        h[i] = h[i - 1] + p[i] * (s[i] - 'a' + 1);
    }

    for (int i = 1; i <= n; i++)
        H.push(substring(i, i));

    scanf("%d", &k);
    for (int i = 1; i < k && H.size(); i++)
    {
        substring x = H.top();
        H.pop();
/*
    for (int j = x.FS; j <= x.SC; j++)
        printf("%c", s[j]);
    printf("\n");
//*/
        x.SC++;
        if (x.SC <= n)
            H.push(x);
    }


    if (H.size() == 0)
    {
        puts("No such line.");
        return 0;
    }

    substring x = H.top();
    for (int i = x.FS; i <= x.SC; i++)
        printf("%c", s[i]);
    printf("\n");

    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}