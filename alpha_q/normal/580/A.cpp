#include <bits/stdc++.h>

using namespace std;

main()
{
    int i, j, n, a, len = 1, crnt = 1; vector<int> V;
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
        scanf("%d", &a);
        V.push_back(a);
    }
    for (i = 0; i < n - 1; i++) {
        if (V[i] <= V[i+1]) crnt++;
        else {
            if (crnt > len) len = crnt;
            crnt = 1;
        }
    }
    if (crnt > len) len = crnt;
    printf("%d\n", len);
}