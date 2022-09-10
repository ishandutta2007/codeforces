#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int MOD = 1'000'000'007;

char in[N];

int main()
{
    int cases;
    scanf("%d", &cases);

    while (cases--) {
        scanf("%s", in + 1);
        int n = strlen(in + 1);

        int ans = 0;
        vector <int> places;

        for (int i = 1; i + 2 <= n; ++i) {
            if (i + 4 <= n && in[i] == 't' && in[i + 1] == 'w' && in[i + 2] == 'o' && in[i + 3] == 'n' && in[i + 4] == 'e') {
                ans++;
                places.push_back(i + 2);
                i += 4;
                continue;
            }

            if (in[i] == 'o' && in[i + 1] == 'n' && in[i + 2] == 'e') {
                ans++;
                places.push_back(i + 1);
            }

            if (in[i] == 't' && in[i + 1] == 'w' && in[i + 2] == 'o') {
                ans++;
                places.push_back(i + 1);
            }
        }

        printf("%d\n", ans);
        for (auto v: places) {
            printf("%d ", v);
        }

        puts("");
    }
    return 0;
}