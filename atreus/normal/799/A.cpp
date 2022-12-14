#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int t, n, k, m;
    cin >> t >> n >> k >> m;
    bool cur = true;
    int p = (m / n) + cur;
    if (p * k >= t)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}