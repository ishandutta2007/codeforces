#include <iostream>
#include <string>

using namespace std;

const long long INF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if(!a) {
        cout << -(long long)b * b << '\n';
        for(int i = 0; i < b; i++)
            cout << 'x';
        cout << '\n';
        return 0;
    }
    if(!b) {
        cout << (long long)a * a << '\n';
        for(int i = 0; i < a; i++)
            cout << 'o';
        cout << '\n';
        return 0;
    }
    int maxi = 0, maxj = 0;
    long long maxs = -INF;
    for(int i = 1; i <= a; i++)
        for(int j = max(1, i - 1); j <= i + 1 && j <= b; j++) {
            long long s = (long long)(a - i + 1) * (a - i + 1) + i - 1 -
                (long long)(b / j + 1) * (b / j + 1) * (b % j) -
                (long long)(b / j) * (b / j) * (j - b % j);
            if(s > maxs) {
                maxs = s;
                maxi = i;
                maxj = j;
            }
        }
    cout << maxs << '\n';
    if(maxj > maxi)
        for(int i = 0; i < maxj; i++) {
            for(int j = 0; j < b / maxj; j++)
                cout << 'x';
            if(i < b % maxj)
                cout << 'x';
            if(!i)
                for(int j = 0; j < a - maxi + 1; j++)
                    cout << 'o';
            else if(i < maxi)
                cout << 'o';
        }
    else {
        for(int i = 0; i < a - maxi + 1; i++)
            cout << 'o';
        for(int i = 0; i < maxj; i++) {
            for(int j = 0; j < b / maxj; j++)
                cout << 'x';
            if(i < b % maxj)
                cout << 'x';
            if(i < maxi - 1)
                cout << 'o';
        }
    }
    cout << '\n';
    return 0;
}