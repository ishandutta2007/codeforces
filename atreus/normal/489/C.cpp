#include <iostream>
#include <string>

using namespace std;

int a[100 + 10], b[100 + 10];

int main()
{
    int n;
    cin >> n;
    int s, s1;
    cin >> s;
    s1 = s;
    int total = 0;
    if (n == 1 && s == 0)
        cout << 0 << " " << 0;
    else if (9 * n < s || s < 1)
        cout << -1 << " " << -1 << endl;
    else{
        a[n - 1] = 1;
        s -= 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 9; j++)
                if (a[i] <= 8 && s >= 1){
                    a[i] += 1;
                    s -= 1;
                }
        }
        for (int i = n - 1; i >= 0; i--)
            cout << a[i];
        cout << endl;
        b[n - 1] = 1;
        s1 -= 1;
        for (int i = n - 1; i >= 0; i--){
            for (int j = 0; j <= 9; j++)
                if (b[i] <= 8 && s1 >= 1){
                    b[i] += 1;
                    s1 -= 1;
                }
        }
        for (int i = n - 1; i >= 0; i--)
            cout << b[i];
    }
}