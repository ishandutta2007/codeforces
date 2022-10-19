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
const int N = 1000006;

int ss;
char s[N];

int h;
int p[N];
int ul[N], ur[N];
bool mergeSort(int l, int r)
{
    if (r - l <= 1)
    {
        if (r - l == 1)
            p[l] = 1;
        return true;
    }
    int m = (l + r) >> 1;
    if (!mergeSort(l, m))
        return false;
    if (!mergeSort(m, r))
        return false;
    for (int i = l; i < m; ++i)
        ul[p[i]] = i;
    for (int i = m; i < r; ++i)
        ur[p[i]] = i;
    int i = l, j = m, k = l;
    while (i < m && j < r)
    {
        // a[i] < a[j]
        if (h == ss)
            return false;
        if (s[h++] == '0')
        {
            //log.append('0');
            //b[k] = a[i];
            p[ul[i - l + 1]] = k - l + 1;
            i += 1;
        }
        // a[i] > a[j]
        else
        {
            //log.append('1');
            //b[k] = a[j];
            p[ur[j - m + 1]] = k - l + 1;
            j += 1;
        }
        k += 1;
    }
    while (i < m)
    {
        //b[k] = a[i];
        p[ul[i - l + 1]] = k - l + 1;
        i += 1;
        k += 1;
    }
    while (j < r)
    {
        //b[k] = a[j];
        p[ur[j - m + 1]] = k - l + 1;
        j += 1;
        k += 1;
    }
    return true;
}

void solv()
{
    cin >> s;
    ss = strlen(s);

    int l = 1, r = 100000;
    int n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        h = 0;
        if (mergeSort(0, m))
        {
            n = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    h = 0;
    mergeSort(0, n);
    cout << n << "\n";
    for (int i = 0; i < n; ++i)
        cout << p[i] << ' ';
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}