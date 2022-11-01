#include <iostream>

using namespace std;

main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) cout << "#";
            cout << endl;
        }
        else if (i % 4 == 1) {
            for (int k = 0; k < m - 1; k++) cout << ".";
            cout << "#" << endl;
        }
        else {
            cout << "#";
            for (int l = 0; l < m - 1; l++) cout << ".";
            cout << endl;
        }
    }
}