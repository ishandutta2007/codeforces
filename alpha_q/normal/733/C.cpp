#include <bits/stdc++.h>

using namespace std;

int n, k;
long long asum = 0, bsum = 0;
vector <long long> a, b;
vector <pair <int, char> > v;

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        long long x; scanf("%lld", &x);
        a.push_back(x), asum += x;
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        long long x; scanf("%lld", &x);
        b.push_back(x), bsum += x;
    }

    if (asum != bsum) {
        puts("NO");
        return 0;
    }

    int flag = 1;

    for (int i = 0; i < k; ++i) {
        long long x = b[i];
        long long sum = 0;
        int pos = i, cur = pos;
        while (pos < a.size() and sum < x) sum += a[pos++];
        if (sum != x) {
            flag = 0;
            break;
        }
        for (int j = cur, till = pos - 1; j < pos - 1; ++j, --till) {
            long long mx = -1;
            int id = -1;
            for (int s = cur; s < till; ++s) {
                if (a[s] != a[s + 1] and a[s] + a[s + 1] > mx) {
                    id = s;
                    mx = a[s] + a[s + 1];
                }
            }
            // for (int i = 0; i < a.size(); ++i) cout << a[i] << " "; cout << endl;
            // cout << id << endl;

            if (id == -1) {
                flag = 0;
                break;
            }

            if (a[id] > a[id + 1]) {
                v.push_back(make_pair(id + 1, 'R'));
            } else {
                v.push_back(make_pair(id + 2, 'L'));
            }

            a.erase(a.begin() + id);
            a.erase(a.begin() + id);
            a.insert(a.begin() + id, mx);
        }
        if (flag == 0) break;
    }

    if (flag == 0) {
        puts("NO");
        return 0;
    }

    puts("YES");
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}