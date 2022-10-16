#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> r(n, -1), c(n, -1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            char ch;
            cin >> ch;
            if(ch == '.') {
                r[i] = j;
                c[j] = i;
            }
        }
    bool br = false, bc = false;
    for(int i = 0; i < n; i++)
        if(r[i] == -1) {
            br = true;
            break;
        }
    for(int i = 0; i < n; i++)
        if(c[i] == -1) {
            bc = true;
            break;
        }
    if(br && bc) {
        cout << -1 << '\n';
        return 0;
    }
    if(!br)
        for(int i = 0; i < n; i++)
            cout << i + 1 << ' ' << r[i] + 1 << '\n';
    else
        for(int i = 0; i < n; i++)
            cout << c[i] + 1 << ' ' << i + 1 << '\n';
}