#include <bits/stdc++.h>
using namespace std;

const int LCM = 2520;

int arr[1010];
int siz[1010];
vector<int> edg[1010];

int nex[1010 * LCM];
int cnt[1010 * LCM];
bool chk[1010 * LCM];

vector<int> v;
void f(int x)
{
    chk[x] = 1;
    v.push_back(x);

    int y = nex[x];
    if(chk[y])
    {
        if(cnt[y])
        {
            cnt[x] = cnt[y];
            return;
        }

        for(auto it = v.begin();; it++)
        {
            assert(it != v.end());
            if(*it == y)
            {
                v.erase(v.begin(), it);
                break;
            }
        }

        for(auto &t : v)
            t = t / LCM;

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        cnt[x] = (int)v.size();
        return;
    }

    f(y);
    cnt[x] = cnt[y];
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &siz[i]);
        for(j = 0; j < siz[i]; j++)
        {
            int x;
            scanf("%d", &x);
            x--;

            edg[i].push_back(x);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < LCM; j++)
        {
            int a = edg[i][((j + arr[i]) % siz[i] + siz[i]) % siz[i]];
            int b = ((j + arr[i]) % LCM + LCM) % LCM;
            nex[i * LCM + j] = a * LCM + b;
        }
    }

    for(i = 0; i < n * LCM; i++)
    {
        if(!chk[i])
        {
            v.clear();
            f(i);
        }
    }

    int q;
    scanf("%d", &q);
    for(i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;

        b = (b % LCM + LCM) % LCM;
        printf("%d\n", cnt[a * LCM + b]);
    }

    return 0;
}