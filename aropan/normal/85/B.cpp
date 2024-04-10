#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

#define T first
#define C second.first
#define I second.second

using namespace std;

const int MAXN = 111111;

typedef pair < long long, pair < int, int > > mpair;
priority_queue < mpair, vector <mpair>, greater <mpair> > H;


int t[3], k[3];
priority_queue < long long, vector <long long>, greater <long long> > h[3];
long long st[MAXN], fn[MAXN];
int n;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);
    #endif
    for (int i = 0; i < 3; i++)
        scanf("%d", &k[i]);
    for (int i = 0; i < 3; i++)
        scanf("%d", &t[i]);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        st[i] = x;
        H.push(make_pair(x, make_pair(0, i)));
    }

    while (H.size())
    {
        mpair curr = H.top();
        H.pop();

        if (curr.C == 3)
        {
            fn[curr.I] = curr.T;
            continue;
        }


        if (h[curr.C].size() < k[curr.C])
            h[curr.C].push(0);

        long long x = h[curr.C].top();
        h[curr.C].pop();
        x = max(x, curr.T) + t[curr.C];

        h[curr.C].push(x);
        H.push(make_pair(x, make_pair(curr.C + 1, curr.I)));
    }


    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, fn[i] - st[i]);

    cout << ans << endl;
    return 0;
}