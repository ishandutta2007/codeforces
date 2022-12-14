#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool f(int a, int b, int n, int m, int k, int l){
    if (n <= a && k <= a && m + l <= b){
        return true;
    }
    return false;
}

int main(){
    int a, b, n, m, k, l;
    cin >> a >> b >> n >> m >> k >> l;
    if (f(a, b, n, m, k, l))
        return cout << "YES", 0;
    if (f(a, b, n, m, l, k))
        return cout << "YES", 0;
    if (f(a, b, m, n, k, l))
        return cout << "YES", 0;
    if (f(a, b, m, n, l, k))
        return cout << "YES", 0;
    if (f(b, a, n, m, k, l))
        return cout << "YES", 0;
    if (f(b, a, n, m, l, k))
        return cout << "YES", 0;
    if (f(b, a, m, n, k, l))
        return cout << "YES", 0;
    if (f(b, a, m, n, l, k))
        return cout << "YES", 0;
    cout << "NO" << endl;
}