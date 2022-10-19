#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int getcnt(int x, vector<int> &facts)
{
    int ans = 0;
    for (int i = 0; i < facts.size(); ++i) {
        ans += (x / facts[i]) * (1 - (__builtin_popcount(i) & 1) * 2);
    }
//		cerr << x << ": " << ans << endl;
    return ans;
}

int main()
{
    int tests; scanf("%d", &tests);
    while (tests--) {
        int x, p, k;
        scanf("%d %d %d", &x, &p, &k);

        vector<int> primefacts;
        for (int i = 2; i * i <= p; ++i) {
            if (p % i == 0) primefacts.push_back(i);
            while (p % i == 0) p /= i;
        }
        if (p > 1) primefacts.push_back(p);

        vector<int> facts((1 << primefacts.size()));
        for (int mask = 0; mask < facts.size(); ++mask) {
            int cur = 1;
            for (int bit = 0; bit < primefacts.size(); ++bit) {
                if ((mask >> bit) & 1)cur *= primefacts[bit];
            }
            facts[mask] = cur;
        }


        k += getcnt(x, facts);

        int l = 1, r = 1e7;
        while (l < r) {
            int m = (l + r) >> 1;
            if (getcnt(m, facts) >= k) r = m;
            else l = m + 1;
        }
        cout << l << '\n';
    }
}