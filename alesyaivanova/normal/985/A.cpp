#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n / 2; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    sort(a, a + n / 2);
    long long ans1 = 0;
    for (int i = 0; i < n / 2; i++)
        ans1 += abs(a[i] - i * 2);
    long long ans2 = 0;
    for (int i = 0; i < n / 2; i++)
        ans2 += abs(a[i] - i * 2 - 1);
    cout << min(ans1, ans2);
}