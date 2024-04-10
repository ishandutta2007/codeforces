#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 10000;

int main()
{
    int n;
    int ans = 0;
    int arr[MAXN];
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        bool f = true;
        for (int j = 2; j < i; j++)
            if (i % j == 0)
                f = false;
        if (f)
            for (int j = i; j <= n; j *= i)
                arr[ans++] = j;
    }
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
        cout << arr[i] << " ";
    
    return 0;
}