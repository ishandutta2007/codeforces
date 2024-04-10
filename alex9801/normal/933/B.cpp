#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <ctime>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    long long p, k;
    scanf("%lld%lld", &p, &k);

    vector<long long> res;

    int endtime = CLOCKS_PER_SEC * 0.9;
    while(p && clock() < endtime)
    {
        long long r = (p % k + k) % k;
        long long q = (r - p) / k;

        res.push_back(r);

        p = q;
    }

    if(p)
        printf("-1");
    else
    {
        printf("%d\n", res.size());
        for(long long &t : res)
            printf("%lld ", t);
    }
    return 0;
}