#include <bits/stdc++.h>
using namespace std;

const int p = 131;
const int q1 = 1000000007;
const int q2 = 1000000009;

int ppow1[5000010];
int ppow2[5000010];

struct hash_t
{
    int h1, h2;
    hash_t(int h = 0) : h1(h), h2(h) {}
    hash_t(int h1, int h2) : h1(h1), h2(h2) {}
    bool operator ==(const hash_t &a) const
    {
        return h1 == a.h1 && h2 == a.h2;
    }
};

hash_t concat(const hash_t &a, const hash_t &b)
{
    return hash_t(
        (1LL * a.h1 * p + b.h1) % q1,
        (1LL * a.h2 * p + b.h2) % q2);
}

hash_t range(hash_t *mem, int l, int r)
{
    return hash_t(
        ((mem[r].h1 - 1LL * mem[l - 1].h1 * ppow1[r - l + 1]) % q1 + q1) % q1,
        ((mem[r].h2 - 1LL * mem[l - 1].h2 * ppow2[r - l + 1]) % q2 + q2) % q2);
}

void init(hash_t *mem, string &s)
{
    for(int i = 0; i < (int)s.size(); i++)
        mem[i + 1] = concat(mem[i], hash_t(s[i]));
}

char buf[5000010];
string arr[300010];

hash_t mem[5000010];
hash_t mem2[5000010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", buf);
        arr[i] = buf;
    }

    ppow1[0] = ppow2[0] = 1;
    for(i = 1; i <= 5000000; i++)
    {
        ppow1[i] = 1LL * ppow1[i - 1] * p % q1;
        ppow2[i] = 1LL * ppow2[i - 1] * p % q2;
    }

    int sz = (int)arr[0].size();
    init(mem, arr[0]);

    string res = arr[0];
    for(i = 1; i < n; i++)
    {
        int l = (int)arr[i].size();

        init(mem2, arr[i]);

        bool ok = 0;
        for(int x = min(sz, l); x >= 0; x--)
        {
            if(mem2[x] == range(mem, sz - x + 1, sz))
            {
                res += arr[i].substr(x);
                for(j = sz + 1; j <= sz + (l - x); j++)
                    mem[j] = concat(mem[j - 1], hash_t(arr[i][j - sz - 1 + x]));

                sz += l - x;
                ok = 1;
                break;
            }
        }
        assert(ok);
    }

    printf("%s\n", res.c_str());
    return 0;
}