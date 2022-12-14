#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

const int maxn = 1e5 + 500;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i] + 1;
    }
    ans -= 1;
    if (ans == x)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}