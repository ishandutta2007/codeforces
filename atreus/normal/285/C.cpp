#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

const int maxn = 3e5 + 100;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort (a, a + n);
    int k = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        int x = a[i] - k;
        if (x < 0)
            x = -x;
        ans += x;
        k ++;
    }
    cout << ans << endl;
}