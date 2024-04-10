#include <bits/stdc++.h>

using namespace std;

namespace fi
{
const
int bsize = 6000000;

char buff[bsize];
int sz;

void start()
{
    sz = fread(buff, 1, bsize, stdin);
}

int i = 0;
typedef double ld;
inline
double get_d()
{
    while (!isdigit(buff[i])) ++i;
    i += 4;
    return buff[i - 4] - '0' + ld(buff[i - 2] - '0') / 10 + ld(buff[i - 1] - '0') / 100;
}

inline
int get_i()
{

    while (!isdigit(buff[i])) ++i;
    int ans(0);
    while (isdigit(buff[i])) ans = ans * 10 + buff[i++] - '0';
    return ans;
}

}

#define MAGIC 300
#define MX 100100

vector<int> g[MX];

int p[MX];
int sum_p[MX];
double all;
bool heavy[MX];

vector<int> hv;
vector<int> hg[MX];

int main()
{
    //freopen("input.txt", "r", stdin);
    fi::start();
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    int n = fi::get_i();//cin >> n;
    all = n;
    for (int i(0); i < n; ++i)
    {
        double db = fi::get_d();
        p[i] = round(db * 100);
        all -= db;
    }
    for (int u, v, i(0); i < n - 1; ++i)
    {
        u = fi::get_i();
        v = fi::get_i();
        g[u].push_back(v);
        g[v].push_back(u);
        all -= double ((100 - p[u]) * (100 - p[v])) / 10000;
    }

    for (int i(0); i < n; ++i) {
        heavy[i] = (g[i].size() >= MAGIC);
        if (heavy[i])
            hv.push_back(i);
    }

    for (int i(0); i < n; ++i)
    {
        for (int j : g[i])
            if (heavy[j])
            {
                hg[i].push_back(j);
                sum_p[j] += 100 - p[i];
            }
    }

    int q = fi::get_i();

    while (q--)
    {
        int v = fi::get_i();
        double db = fi::get_d(); int p_ = round(db * 100);
        int delta = p_ - p[v];
        db = delta;
        db /= 10000;
        if (heavy[v])
        {
            all += (db * sum_p[v]);
        }
        else
        {
            for (int u : g[v])
            {
                all += (db * (100 - p[u]));
            }
        }

        all -= db * 100;

        for (int u : hg[v])
        {
            sum_p[u] -= delta;
        }
        p[v] = p_;

//        fixed(cout);
//        cout << setprecision(10) << all << '\n';
        printf("%.5f\n", all);
    }
}