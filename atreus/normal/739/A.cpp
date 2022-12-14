#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k = 1000000000;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        k = min(k, b - a + 1);
    }
    int p = 0;
    cout << k << endl;
    while (n --){
        cout << p << " ";
        p ++;
        if (p == k)
            p = 0;
    }
}