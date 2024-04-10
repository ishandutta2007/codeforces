#include <iostream>

using namespace std;

int main (){
    long long n, k;
    long long c = 0;
    cin >> n >> k;
    int ans = 0;
    int a[100 + 10];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++){
        a[i] += c;
        c = 0;
        if (k <= 0)
            break;
        if (a[i] / 8 >= 1){
            k -= 8;
            a[i] -= 8;
            c += a[i];
        }
        else{
            k -= a[i] % 8;;
            a[i] = 0;
        }
        ans ++;

    }
    if (ans > n || k > 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
}