#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, d;
int a[N], b[N];

ll x;
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int u[N];

void solv()
{
    cin >> n >> d >> x;
    initAB();
    for (int i = 0; i < n; ++i)
        u[a[i]] = i;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == 1)
            v.push_back(i);
    }
    for (int i = 0; i < n; ++i)
    {
        int ans = 0;
        for (int j = n; j >= max(1, n - 1000); --j)
        {
            if (u[j] <= i)
            {
                if (b[i - u[j]])
                {
                    ans = j;
                    break;
                }
            }
        }
        if (!ans)
        {
            for (int k = 0; k < v.size(); ++k)
            {
                if (v[k] > i)
                    break;
                ans = max(ans, a[i - v[k]]);
            }
        }
        printf("%d\n", ans);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}