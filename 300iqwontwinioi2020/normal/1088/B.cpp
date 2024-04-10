
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;


int n, k, a[N];


int main()
{
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    sort (a + 1, a + n + 1);
    for (int i = 0; i < n; i++){
        if (a[i + 1] == a[i])
            continue;
        cout<<a[i + 1] - a[i]<<endl;
        k--;
        if (k == 0)
            return 0;
    }
    while (k--)
        cout<<0<<endl;
    return 0;
}