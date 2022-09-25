#include <bits/stdc++.h>

using namespace std;

char q(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);

    char c;
    scanf(" %c", &c);

    return c;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> L, R;
        for (int i = 0; i + 1 < n; i += 2) {
            char c = q(i + 1, i + 2);

            if (c == '<') {
                L.push_back(i + 1);
                R.push_back(i + 2);
            }
            else {
                L.push_back(i + 2);
                R.push_back(i + 1);
            }
        }

        if (n % 2 == 1) {
            L.push_back(n);
            R.push_back(n);
        }

        int mn = L[0];
        for (int i = 1; i < L.size(); i++)
            if (q(mn, L[i]) == '>')
                mn = L[i];

        int mx = R[0];
        for (int i = 1; i < R.size(); i++)
            if (q(mx, R[i]) == '<')
                mx = R[i];

        printf("! %d %d\n", mn, mx);
        fflush(stdout);
    }

    return 0;
}