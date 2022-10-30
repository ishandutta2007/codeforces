#include <bits/stdc++.h>

using namespace std;

long long n, ki, s, a[1001], b[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
   for(int i=1;i<=n;i++) {
        cin >> b[i];
    }
    if(a[1]!=1) {
        cout << "NO" << endl;
        return 0;
    }
    if(a[s]==1) {
        cout << "YES" << endl;
        return 0;
    }
    if(b[s]!=1) {
        cout << "NO" << endl;
        return 0;
    }
    for(int i=s+1;i<=n;i++) {
        if(a[i]==1 && b[i]==1) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}