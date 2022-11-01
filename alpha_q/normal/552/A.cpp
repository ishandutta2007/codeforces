#include <bits/stdc++.h>

#define FOR(it, from, to) for (it = from; it < to; it++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vs vector<string>
#define vvi vector<vi>
#define vvii vector< vector< pair<int, int> > >
#define in(vec, elem) vec.push_back(elem)
#define mem0(ar) memset(ar, 0, sizeof(ar))
#define mem1(ar) memset(ar, -1, sizeof(ar))
#define mii map<int, int>
#define msi map<string, int>
#define msvi map<string, vector<int, int> >

using namespace std;

main()
{
    int n, x1, x2, y1, y2, res = 0; scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        res += (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    printf("%d\n", res);
}