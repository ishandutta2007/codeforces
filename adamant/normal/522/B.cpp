#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int max1 = 0, max2 = 0, sum = 0;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
        if(b[i] > max1)
        {
            max2 = max1;
            max1 = b[i];
        }
        else if(b[i] > max2)
        {
            max2 = b[i];
        }
    }
    for(int i = 0; i < n; i++)
        cout << (sum - a[i]) * (max1 == b[i] ? max2 : max1) << ' ';
}