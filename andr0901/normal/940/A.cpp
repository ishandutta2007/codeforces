#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    vector <int> a (n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[i] > a[j]) swap (a[i], a[j]);
        }
    }
    int s = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (a[j] - a[i] <= d) {
                if (j - i > s) {
                    s = j - i;

                }
            }
        }
    }
    cout << n - s - 1;
    return 0;
}