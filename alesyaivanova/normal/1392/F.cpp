#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e6 + 9;
int a[maxn];
int pos[maxn];
int n, pt;
int inf = 1e12 + 9;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int kek = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        kek += a[i];
    }
    int lst = a[0];
    for (int i = 1; i < n; i++)
    {
        while (a[i] > lst + 1 && pt)
        {
            int e = pos[pt - 1];
            pt--;
            if (a[i] - (i - e) >= lst + 1)
            {
                a[i] -= (i - e);
                lst++;
            }
            else
            {
                int x = a[i] - (lst + 1);
                a[i] = lst + 1;
                pos[pt] = e + x;
                pt++;
            }
        }
        if (a[i] > lst + 1)
        {
            int left = 0, right = inf;
            while (right - left > 1)
            {
                int mid = (left + right) / 2;
                if (a[i] - i * mid >= lst + mid)
                    left = mid;
                else
                    right = mid;
            }
            a[i] -= left * i;
            lst += left;
            int x = a[i] - (lst + 1);
            if (x > 0)
            {
                pos[pt] = x;
                pt++;
                a[i] = lst + 1;
            }
        }
        if (a[i] == lst)
        {
            pos[pt] = i;
            pt++;
        }
//        cout << lst << " " << a[i] << "\n";
        lst = a[i];
    }
    int sum = 0;
    int cur = 0;
    int e = 0;
    for (int i = 0; i < n; i++)
    {
        sum += cur;
        if (e < pt && pos[e] == i + 1)
            e++;
        else
            cur++;
    }
    cur = (kek - sum) / n;
    e = 0;
    for (int i = 0; i < n; i++)
    {
        cout << cur << " ";
        if (e < pt && pos[e] == i + 1)
            e++;
        else
            cur++;
    }
}