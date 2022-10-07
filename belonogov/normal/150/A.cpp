#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  long long n, res = 1, cnt = 1, i;
    cin >> n;
    for (i = 2; i * i <= n; i++){
        while (n % i == 0 && i < n){
            n /= i;
            if (cnt <= 2)
                res *= i;
            cnt++;
        }
    }
   if (cnt == 1){
        cout << 1 << endl << 0;
        return 0;
    }
    if (cnt >= 3){
        cout << 1 << endl;
        cout << res;
    }
    else
        cout << 2;
    return 0;
}