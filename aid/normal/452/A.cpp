#include <iostream>
#include <string>

using namespace std;
const int N = 8;
string s[N];

int main() {
    ios_base::sync_with_stdio(false);
    s[0] = "vaporeon";
    s[1] = "jolteon";
    s[2] = "flareon";
    s[3] = "espeon";
    s[4] = "umbreon";
    s[5] = "leafeon";
    s[6] = "glaceon";
    s[7] = "sylveon";
    int n;
    string t;
    cin >> n >> t;
    for(int i = 0; i < N; i++)
        if((int)s[i].length() == n) {
            bool b = true;
            for(int j = 0; j < n; j++)
                if(t[j] != '.' && t[j] != s[i][j]) {
                    b = false;
                    break;
                }
            if(b) {
                cout << s[i] << '\n';
                return 0;
            }
        }
    return 0;
}