#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n;
    int ans = 0;
    int used = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        if (a[i] == i)
            ans++;
        else
            if(used == 0 && a[a[i]] == i)
            {
                swap(a[i], a[a[i]]);
                ans++;
                used = 1;
            }
    if (used == 0 && ans < n)
        ans++;
    cout << ans;
    return 0;
}