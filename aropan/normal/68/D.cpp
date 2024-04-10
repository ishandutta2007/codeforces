#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

#define E second.first
#define S second.second

const int MAXL = 10;

map < int, pair <int, int> > t;

char c[MAXL];
map < int, pair <int, int> > :: iterator zero, curr, left, right;
int n;
long long h;

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/    
    t[0] = make_pair(0, 0);
    zero = t.find(0);

    scanf("%d %d", &h, &n);
    h = 1LL << (h + 1);
    while (n--)
    {
        scanf("%s", c);
        if (strcmp(c, "add") == 0)
        {
            int x, e;
            scanf("%d %d", &x, &e);
            if (e)
            {
                t[x].first += e;

                while (x)
                {
                    t[x].second += e;
                    x >>= 1;
                }
            }
        }
        else
        {
            long double ans = 0, p = 1;
            int m = 0;
            int x = 1;
            while (x < h)
            {
                curr = t.find(x);
                left = t.find(x << 1);
                right = t.find((x << 1) + 1);
                if (curr == t.end()) curr = zero;
                if (left == t.end()) left = zero;
                if (right == t.end()) right = zero;

                if (left->S == right->S)
                {
                    ans += max(m, left->S + curr->E) * p;
                    break;
                }

                p *= 0.5;
                ans += p * max(m, (max(left->S, right->S) + curr->E));
                m = max(m, min(left->S, right->S) + curr->E);
                x = (x << 1) + (left->S < right->S);
            }
            printf("%.10lf\n", (double) ans);
        }
        gets(c);
    }
    
    return 0;
}