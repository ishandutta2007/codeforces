#include <iostream>
#include <set>

using namespace std;

int main() {
    long int a;
    set<long int> s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    s.insert(a);
    cin >> a;
    s.insert(a);
    cin >> a;
    s.insert(a);
    cin >> a;
    s.insert(a);
    cout << 4-s.size();
    return 0;
}