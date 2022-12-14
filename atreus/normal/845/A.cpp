#include <iostream>
#include <algorithm>

using namespace std;

long long a[10000];

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort (a, a + 2 * n);
    if (a[n] == a[n - 1])
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}