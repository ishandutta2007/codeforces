#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int k = 1;
    vector <pair <int, int> > ans;

    while (2 * (n - k) - 1 > k) {
        ++k;
    }

    int offset = 0;
    auto add = [&](int s) {
        if (s < 0) {
            return;
        }

        int ptr = offset + 1, last = offset + s + 1;
        while (ptr <= last) {
            ans.push_back({ptr, last});
            if (ptr != last) {
                ans.push_back({last, ptr});
            }

            ptr++, last--;
        }

        offset += s + 1;
    };

    int m = n - k;
    add(m - 1);
    add(m - 2);
    
    while (offset < k) {
        ++offset;
        ans.push_back({offset, offset});
    }

    printf("%lu\n", ans.size());
    for (auto [x, y]: ans) {
        printf("%d %d\n", x, y);
    }
    return 0;
}