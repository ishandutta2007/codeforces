#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(auto &it: a)
        cin >> it;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            for(int k = 0; k < j; k++)
            {
                if(a[i] != a[j] && a[i] != a[k] && a[j] != a[k])
                    if(abs(a[i] - a[j]) <= 2 && abs(a[i] - a[k]) <= 2 && abs(a[j] - a[k]) <= 2)
                    {
                        cout << "YES\n";
                        return 0;
                    }
            }
    cout << "NO\n";
}