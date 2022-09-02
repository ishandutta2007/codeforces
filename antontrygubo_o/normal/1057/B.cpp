#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{

    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i<n; i++) cin>>a[i];
    int ans = 0;
    for (int i = 0; i<n; i++) a[i]-=100;
    int temp;
    for (int i = n-1; i>=0; i--)
    {
        temp = a[i];
        if (temp>0) ans = max(ans, 1);
        for (int j = i+1; j<n; j++)
        {
            temp+=a[j];
            if (temp>0) ans = max(ans, j-i+1);
        }
    }
    cout<<ans;
}