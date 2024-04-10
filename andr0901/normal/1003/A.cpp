#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(101);
    for (int i = 0; i < 101; i++) a[i] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int m = 0;
    for (int i = 0; i < 101; i++) {
        if (a[i] > m) m = a[i];
    }
    cout << m;
    return 0;
}