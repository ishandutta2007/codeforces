#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SPEED cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
#define endl '\n'
#define cyc(n) for(int i=0;i<n;i++)
#define cycS(s, n) for(int i=s;i<n;i++)
void z984A(){
    SPEED;
    int n;
    cin >> n;
    int a[n];
    cyc(n) cin >> a[i];
    sort(a, a+n);
    cout << a[n/2 - (1-(n%2))];
}
main(){
    z984A();
}