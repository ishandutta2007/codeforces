#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e5;
int a[maxn + 100], b[maxn + 100], c[maxn + 100];

int main(){
    int n;
    cin >> n;
    long long ans = n;
    for (int i = n - 1; i >= 1; i--){
        ans += (n - i) * i;
    }
    cout << ans << endl;
}