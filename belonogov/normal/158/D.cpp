#include <iostream>
#include <cstdio>

using namespace std;
const int inf = -1e9;
int a[200000];

int main(){
    int n, i, j, ii, k, sum, ans = inf;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 1; i <= n / 3; i++)
        if (n % i == 0){
            for (j = 0; j < i; j++){
                sum = 0;
                for (ii = j; ii < n; ii += i)
                    sum +=a[ii];
                ans = max(sum, ans);
            }

        }

    cout << ans;
    return 0;
}