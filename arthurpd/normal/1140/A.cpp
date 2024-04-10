#include <bits/stdc++.h>
using namespace std;


int a[112345];

int main(void)
{
    int n;
    cin >> n;

    for(int i = 0; i < n; a[i]--, i++)
        cin >> a[i];
    
    int i = 0;
    int k = 0;
    int ans = 0;
    while (true)
    {
        ans++;
        k = a[i];
        while (i < k)
        {
            i++;
            k = max(k, a[i]);
        }

        i++;
        if (k == n - 1)
            break;
    }

    cout << ans << endl;
}