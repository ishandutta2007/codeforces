#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 18;
string e[105] = {"", "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm"};
map<string, int> re;

int n, k;
int a[N], b[N];

vector<int> v[N * N];
int dp[(1 << N)];
int p[(1 << N)];

void solv()
{
    for (int i = 1; i <= 100; ++i)
        re[e[i]] = i;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        string x;
        cin >> x;
        a[i] = re[x];
    }
    for (int i = 1; i <= k; ++i)
    {
        string x;
        cin >> x;
        b[i] = re[x];
    }
    for (int x = 1; x < (1 << n); ++x)
    {
        int s = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
            {
                s += a[i];
            }
        }
        if (s <= 100)
            v[s].push_back(x);
    }
    for (int x = 1; x < (1 << n); ++x)
        dp[x] = -1;
    for (int x = 0; x < (1 << n); ++x)
    {
        if (dp[x] == -1)
            continue;
        for (int i = 0; i < v[b[dp[x] + 1]].size(); ++i)
        {
            int y = v[b[dp[x] + 1]][i];
            if ((x & y) == 0)
            {
                dp[(x | y)] = dp[x] + 1;
                p[(x | y)] = y;
            }
        }
    }
    if (dp[(1 << n) - 1] != k)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int x = (1 << n) - 1;
    for (int i = k; i >= 1; --i)
    {
        vector<int> v;
        for (int j = 0; j < n; ++j)
        {
            if ((p[x] & (1 << j)))
                v.push_back(j);
        }
        for (int i = 0; i < v.size() - 1; ++i)
            cout << e[a[v[i]]] << '+';
        cout << e[a[v.back()]] << "->";
        cout << e[b[i]] << endl;
        x = (x ^ p[x]);
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    /*for (int i = 0; i < 100; ++i)
    {
        string s[4];
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        cout << '"' << s[1] << '"' << ", ";
    }*/
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}