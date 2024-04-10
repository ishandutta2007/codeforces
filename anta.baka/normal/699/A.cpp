#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
char a[N];
int b[N];

int main()
{
    int n;
    cin >> n;
    bool f = 0, s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 'R') f = 1;
        if(f && a[i] == 'L') s = 1;
    }
    for(int i = 0; i < n; i++)
        cin >> b[i];
    if(!s) {
        cout << -1;
        return 0;
    }
    int l = -1000000000, ans = 1000000000;
    for(int i = 0; i < n; i++) {
        if(a[i] == 'R') l = b[i];
        else ans = min(ans, (b[i] - l) / 2);
    }
    cout << ans;
    return 0;
}