#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n == 1){
        cout << 1 << ' ' << n << '\n';
        cout << -a[0] << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 0 << '\n';
        return 0;
    }
    if(n == 2){
        cout << 1 << ' ' << 1 << '\n';
        cout << -a[0] << '\n';
        cout << 2 << ' ' << 2 << '\n';
        cout << -a[1] << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 0 << ' ' << 0 << '\n';
        return 0;
    }
    vector<int> b(n);
    int k = 0;
    for(int i = 0; i < n; ++i){
        b[k%n] = k;
        k += n-1;
    }
    vector<int> a1(n), a2(n);
    for(int i = 0; i < n-1; ++i){
        int c = a[i]%n;
        if(c < 0)
            c += n;
        a1[i] = -b[c];
        a[i] += a1[i];
    }
    for(int i = n-1; i < n; ++i){
        int c = a[i]%n;
        if(c < 0)
            c += n;
        a2[i] = -b[c];
        a[i] += a2[i];
    }
    cout << 1 << ' ' << n-1 << '\n';
    for(int i = 0; i < n-1; ++i)
        cout << a1[i] << ' ';
    cout << '\n';
    cout << 2 << ' ' << n << '\n';
    for(int i = 1; i < n; ++i)
        cout << a2[i] << ' ';
    cout << '\n';
    cout << 1 << ' ' << n << '\n';
    for(int i = 0; i < n; ++i)
        cout << -a[i] << ' ';
    return 0;
}