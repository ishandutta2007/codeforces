#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int bit[100010];
int n;

void upd(int x, int v)
{
    x++;
    while(x <= n)
    {
        bit[x] += v;
        x += x&-x;
    }
}

int sum(int x)
{
    x++;
    int r = 0;
    while(x)
    {
        r += bit[x];
        x -= x&-x;
    }
    return r;
}

struct str
{
    int x, i;
    bool operator <(const str &a) const
    {
        return x != a.x ? x < a.x : i < a.i;
    }
};

int arr[100010];
str pos[100010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int p, c, t, i;
    long long r;
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i<n; i++)
        pos[i] = { arr[i], i };
    sort(pos, pos+n);

    for(i = 0; i<n; i++)
        upd(i, 1);

    p = 0;
    c = 0;
    r = 0;
    while(p<n)
    {
        vector<int> tmp;
        tmp.push_back(pos[p++].i);
        while(p<n && pos[p].x == pos[p-1].x)
            tmp.push_back(pos[p++].i);

        if(tmp[0] >= c)
        {
            r += sum(tmp.back()) - sum(c-1);
            for(int e : tmp)
                upd(e, -1);

            c = (tmp.back()+1) % n;
        }
        else
        {
            for(i = tmp.size()-1; i>=0; i--)
            {
                if(tmp[i] < c)
                {
                    t = tmp[i];
                    break;
                }
            }

            r += sum(n-1) - sum(c-1);
            r += sum(t);

            for(int e : tmp)
                upd(e, -1);

            c = (t+1) % n;
        }
    }
    printf("%lld", r);
    return 0;
}