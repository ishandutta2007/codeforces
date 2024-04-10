#include <cstdio>
#include <algorithm>
#include <vector>
#include <ctime>

#define L first
#define R second

using namespace std;

int l1, r1, l2, r2;

int rec(int k, int l1, int r1, int l2, int r2) 
{
    int res = max(0, min(r1, r2) - max(l1, l2) + 1);
    if (r1 - l1 + 1 == res || r2 - l2 + 1== res) return res;

    vector < pair <int, int> > a, b;

    int c = (1 << (k - 1));
    if (l1 < c) a.push_back(make_pair(l1, min(r1, c - 1)));
    if (c < r1) a.push_back(make_pair(max(l1, c + 1) - c, r1 - c));

    if (l2 < c) b.push_back(make_pair(l2, min(r2, c - 1)));
    if (c < r2) b.push_back(make_pair(max(l2, c + 1) - c, r2 - c));

//    printf("%d (%d %d) (%d %d) %d %d\n", k, l1, r1, l2, r2, a.size(), b.size());
    for (int i = 0; i < (int)a.size(); i++)
        for (int j = 0; j < (int)b.size(); j++)
            res = max(res, rec(k - 1, a[i].L, a[i].R, b[j].L, b[j].R));
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen(".in", "r", stdin);
        freopen(".out", "w", stdout);
    #endif

    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    printf("%d\n", rec(30, l1, r1, l2, r2));

    fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}