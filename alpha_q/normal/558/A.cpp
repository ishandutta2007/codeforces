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
    long long res = 0; int i, n, x, a;
    vii left, right; scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &x, &a);
        ii p; p.first = x; p.second = a;
        if (x > 0) in(right, p);
        else in(left, p);
    }
    sort(left.begin(), left.end());
    reverse(left.begin(), left.end());
    sort(right.begin(), right.end());
    int siz = min(left.size(), right.size());
    FOR (i, 0, siz) {
        res += left[i].second;
        res += right[i].second;
    }
    if (left.size() != right.size()) {
        if (siz == left.size()) res += right[siz].second;
        else if (siz == right.size()) res += left[siz].second;
    }
    cout << res << endl;
}