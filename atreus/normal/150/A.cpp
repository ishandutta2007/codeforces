#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 500;
set <int> s;
map <int, int> mp, dp;
int a[maxn];

bool isprimeor1(long long n){
    if (n == 1)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    long long n, k;
    cin >> n;
    bool cur = false;
    if (isprimeor1(n)){
        cout << 1 << endl << 0;
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            if (cur == true){
                cout << 1 << endl;
                cout << k * i << endl;
                return 0;
            }
            cur = true;
            k = i;
            n /= i;
            i --;
        }
    }
    cout << 2 << endl;
}