#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 77;
int n , a[N] , f[N];
void test() {
    cin >> n;
    for(int i = 1;i <= n;++ i)
        cin >> a[i];
    if(n % 2 == 1) {
        cout << "NO\n";
        return ;
    }
    sort(a + 1 , a + 1 + n);
    for(int i = 1;i <= n / 2;++ i) {
        f[(i << 1) - 1] = a[i];
        f[i << 1] = a[i + n / 2];
    }
    f[0] = a[n];
    f[n + 1] = a[1];
    for(int i = 1;i <= n;i += 2)
        if(f[i] >= f[i - 1] || f[i] >= f[i + 1]) {
            cout << "NO\n";
            return ;
        }
    cout << "YES\n";
    for(int i = 1;i <= n;++ i)
        cout << f[i] << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int tst;
    cin >> tst;
    while(tst --)
        test();
    return 0;

}