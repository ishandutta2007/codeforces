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

using namespace std;

vector<int> res;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, t, c, i;
    scanf("%d", &n);

    for(i = n - 100; i < n; i++)
    {
        if(i <= 0)
            continue;

        t = i;
        c = i;
        while(t)
        {
            c += t % 10;
            t /= 10;
        }
        if(c == n)
            res.push_back(i);
    }
    if(res.empty())
        printf("0");
    else
    {
        printf("%d\n", res.size());
        for(int t : res)
            printf("%d\n", t);
    }
    return 0;
}