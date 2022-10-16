#include <iostream>
#include <algorithm>
#include <vector>

#define lint long long int
using namespace std;

const int NMAX = 200025;

int n;
int v[NMAX];

lint s_part[NMAX];

lint sum(int st, int dr) {
    return s_part[dr] - s_part[st - 1];
}

double get_val(int where, int sz) {
    return (sum(where - sz, where) + sum(n - sz + 1, n))/ (2.0 * sz + 1) - v[where];
}

vector <int> get_ans(int where, int sz) {
    vector <int> ans;

    for (int i = where - sz; i <= where; ++ i)
        ans.push_back(v[i]);
    for (int i = n - sz + 1; i <= n; ++ i)
        ans.push_back(v[i]);

    return ans;
}

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];
    sort(v + 1, v + n + 1);

    for (int i = 1; i <= n; ++ i)
        s_part[i] = v[i] + s_part[i - 1];

    double best = 0;
    int where = 1, sz = 0;

    double val1, val2;
    for (int i = 1; i <= n; ++ i) {
        int st = 0, dr = min(i - 1, n - i);
        int mid1, mid2;
        int ans = 0;

        while (st + 1 < dr) {
            mid1 = (2 * st + dr) / 3;
            mid2 = (st + 2 * dr) / 3;

            val1 = get_val(i, mid1);
            val2 = get_val(i, mid2);
            if (val1 < val2) {
                st = mid1 + 1;
                ans = dr;
            }
            else {
                dr = mid2 - 1;
                ans = st;
            }
        }

        if (st + 1 == dr) {
            if (get_val(i, st) < get_val(i, dr))
                ans = dr;
            else
                ans = st;
        }

        double aux = get_val(i, ans);
        if (best < aux) {
            best = aux;

            where = i;
            sz = ans;
        }
    }

    vector <int> ans = get_ans(where, sz);
    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++ i)
        cout << ans[i] << " \n"[i + 1 == ans.size()];
        
    return 0;
}