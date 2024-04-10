#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, j, n, ans = 0;
    bool check;
    string a[2000][2];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }

    for (i = 0; i < n; i++)
    {
        check = true;
        for (j = i + 1; j < n; j++)
            if (a[i][0] == a[j][0] && a[i][1] == a[j][1])
                check = false;
        if (check)
            ans++;
    }
    cout << ans;
    return 0;
}