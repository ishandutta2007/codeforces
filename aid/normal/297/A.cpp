#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int ca = 0, cb = 0;
    for(size_t i = 0; i < a.length(); i++)
        if(a[i] == '1')
            ca++;
    for(size_t i = 0; i < b.length(); i++)
        if(b[i] == '1')
            cb++;
    if(ca + (ca & 1) < cb)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}