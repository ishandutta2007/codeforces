#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 12; i++)
        cin >> a[i];
    sort(a, a + 12);
    int ans = 0;
    int su = 0;
    int cur = 11;
    while(cur >= 0 && su < n)
    {
        ans++;
        su += a[cur];
        cur--;
    }
    if(su < n)
        cout << -1;
    else
        cout << ans;
    return 0;
}