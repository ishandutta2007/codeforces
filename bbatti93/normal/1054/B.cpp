#include <bits/stdc++.h>

using namespace std;

int n, ki, t[100001], nx=0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t[i];
    }
    int i;
    for(i=0;i<n;i++) {
        if(t[i]>nx) break;
        if(t[i]==nx) nx++;
    }
    if(i==n) cout << -1 << endl;
    else cout << i+1 << endl;
    return 0;
}