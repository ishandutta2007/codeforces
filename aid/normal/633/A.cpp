#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i * a <= c; i++)
        if(!((c - i * a) % b)) {
            cout << "Yes\n";
            return 0;
        }
    cout << "No\n";
    return 0;
}