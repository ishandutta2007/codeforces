#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    cout << "3\n";
    cout << "L 2\n";
    int n = s.size()+1;
    cout << "R " << 2 << '\n';
    n = n+n-2;
    cout << "R " << n-1 << '\n';
    return 0;
}