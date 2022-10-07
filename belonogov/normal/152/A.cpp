#include <iostream>
#include <cstdio>

using namespace std;
struct SS{
    string s;
};
SS s[100];
bool use[100];
char best[100];

int main()
{
    int n, m, i, j, cnt;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> s[i].s;
    for (i = 0; i < m; i++){
        best[i] = '0';
        for (j = 0; j < n; j++)
            best[i] = max(best[i], s[j].s[i]);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (s[i].s[j] == best[j])
                use[i] = true;
    cnt = 0;
    for (i = 0; i < n; i++)
        if (use[i])
            cnt++;

    cout << cnt;

    return 0;
}