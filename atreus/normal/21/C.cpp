#include <iostream>

using namespace std;

const int maxn = 500000 + 10;

int a[maxn];

int x[maxn], y[maxn];

int main(){
    long long int n, total = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        total += a[i];
    }
    if (total % 3 == 0){
        int miangin = total / 3;
        int w = 0, q = 0;
        for (int i = 0; i < n; i++){
            w += a[i];
            if (w == miangin)
                x[i] = 1;
            else
                x[i] = 0;
        }
        for (int j = n - 1; j >= 0; j--){
            q += a[j];
            if (q == miangin)
                y[j] = 1;
            else
                y[j] = 0;
        }
        long long p = 0, s = 0;
        for (int i = 0; i < n; i++){
            if (y[i] == 1)
                s += p;
            if (i - 1 >= 0 && x[i - 1] == 1)
                p += 1;
            }
            cout << s << endl;
    }
    else
        cout << 0 << endl;
}