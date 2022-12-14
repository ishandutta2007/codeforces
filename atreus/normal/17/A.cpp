#include <iostream>

using namespace std;

bool isprime (int n){
    int o = 0;
    for (int i = 2; i < n; i++){
        if (n % i == 0)
            return 0;
    }
    return 1;
}
bool f(int n){
    int ans, cnt;
    if (isprime (n) == 0)
        return 0;
    n -= 1;
    if (n % 2 == 1)
        return 0;
    int m = n;
    n /= 2;

    for (int i = n; i <= n + 100; i++){
        if (isprime (i) == 1){
            ans = i;
            break;
        }
    }
    for (int i = n - 1; i >= n - 100; i--){
        if (isprime (i) == 1){
            cnt = i;
            break;
        }
    }
    if (cnt + ans == m){
        return 1;
    }
    else
        return 0;
}
int main (){
    int n, k, answer = 0;
    cin >> n >> k;
    if (n < 13){
        if (k == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else {
        for (int i = 13; i <= n; i++){
            if (f(i) == 1)
                answer ++;
        }
        if (answer >= k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}