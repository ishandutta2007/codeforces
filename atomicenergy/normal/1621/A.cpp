

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>


using namespace std;

int main(){
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        if (k > (n + 1) / 2) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && i % 2 == 0 && k > 0) {
                    k--;
                    cout << 'R';
                }
                else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }


}