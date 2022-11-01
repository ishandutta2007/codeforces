#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int a[10000000];
int b[10000000];
int c[10000000];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int n;
    //cin >> n;
    //for(int i = 0; i < n; i++)
    //cin >> a[i];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    int cur1 = n - 1;
    int cur2 = m - 1;
    int ans = 0;
    while(cur1 >= 0 && cur2 >= 0)
    {
        if(!(a[cur1] <= b[cur2]))
        {
            ans++;
            cur1--;
        }
        else
        {
            cur1--;
            cur2--;
        }
    }
    ans += (cur1 + 1);
    cout <<ans;
    return 0;
}