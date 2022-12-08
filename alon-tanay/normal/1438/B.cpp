#include <iostream>
#include <set>

using namespace std;

int main() {
    set<long int> numbers;
    int t, n, len;
    long int b;
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    for(int i = 0; i < t; i ++) {
        numbers.clear();
        bool right = false;
        cin >> n;
        len = 0;
        for(int j = 0; j < n; j ++) {
            cin >> b;
            numbers.insert(b);
            if(len == numbers.size()) {
                right = true;
            }
            len = numbers.size();
        }
        cout << (right ? "YES" : "NO") << endl;
        
    }
    return 0;
}