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
const int N = 200005;

int n;
char a[N];

deque<int> v[10];

void solv()
{
    cin >> a;
    n = strlen(a);

    for (int i = 0; i < n; ++i)
        v[a[i] - '0'].push_back(i);
    int q[10] = {};
    for (int ii = 0; ii < n; ++ii)
    {
        int minu = N;
        for (int i = 0; i < 10; ++i)
        {
            if (!v[i].empty())
                minu = min(minu, v[i][0]);
        }

        if (minu == N)
        {
            for (int i = 0; i < 10; ++i)
            {
                if (q[i])
                {
                    cout << i;
                    --q[i];
                    break;
                }
            }
            continue;
        }

        for (int i = 0; i < 10; ++i)
        {
            if (!v[i].empty() && minu == v[i][0])
            {
                bool z = false;
                for (int j = 0; j <= i - 1; ++j)
                {
                    if (!v[j].empty() || q[j])
                    {
                        cout << j;
                        if (q[j])
                            --q[j];
                        else
                        {
                            for (int k = 0; k < 10; ++k)
                            {
                                while (!v[k].empty() && v[k].front() < v[j].front())
                                {
                                    ++q[min(9, k + 1)];
                                    v[k].pop_front();
                                }
                            }
                            v[j].pop_front();
                        }
                        z = true;
                        break;
                    }
                }
                if (!z)
                {
                    cout << i;
                    v[i].pop_front();
                }
                break;
            }
        }
    }
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}