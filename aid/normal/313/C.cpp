#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    long long b = 0;
    while(n > 0) {
        for(int i = 0; i < n; i++)
            b +=a[i];
        n /=4;
    }
    cout << b << '\n';
}