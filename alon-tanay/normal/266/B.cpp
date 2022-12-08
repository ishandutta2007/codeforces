#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, t;
    char curr;
    string line;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    cin >> line;
    for(int ti = 0; ti < t; ti ++) {
        for(int i = n-1; i > 0; i --) {
            if(line[i] == 'G' && line[i-1] == 'B') {
                line[i] = 'B';
                line[i-1] = 'G';
                i--;
            }
        }
    }
    cout << line;
    return 0;
}