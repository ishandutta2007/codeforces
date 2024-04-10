#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a;
    cin >> a;
    while(a % 2 == 0)
        a /= 2;
    while(a % 3 == 0)
        a /= 3;
    int t = a;
    for(int i = 1; i < n; i++)
    {
        cin >> a;
        while(a % 2 == 0)
            a /= 2;
        while(a % 3 == 0)
            a /= 3;
        if(a != t)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

	return 0;
}