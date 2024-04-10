#include <bits/stdc++.h>

#define lint long long int
#define lsb(x) ((x) & (-(x)))
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf (1 << 30)
using namespace std;

int main()
{
    int n;
    int min1, max1;
    int min2, max2;
    int min3, max3;

    cin >> n;
    cin >> min1 >> max1;
    cin >> min2 >> max2;
    cin >> min3 >> max3;

    int ans1 = min1;
    int ans2 = min2;
    int ans3 = min3;

    n -= min1;
    n -= min2;
    n -= min3;

    max1 -= min1;
    max2 -= min2;
    max3 -= min3;

    while (n && max1) {
        ans1 ++;
        max1 --;

        n--;
    }
    
    while (n && max2) {
        ans2 ++;
        max2 --;
        n--;
    }
    
    while (n && max3) {
        ans3 ++;
        max3 --;
        n--;
    }


    cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    return 0;
}