#include <iostream>
#include <set>

using namespace std;


int main() {
    int tc;
    for (cin >> tc; tc --> 0; ) {
        int n;
        set<int> was;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            was.insert(was.count(x) ? -x : x);
        }
        cout << was.size() << endl;
    }
    return 0;
}