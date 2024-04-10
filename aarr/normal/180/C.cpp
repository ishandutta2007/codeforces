#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int l[N];
int u[N];

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i > 0) {
            l[i] = l[i - 1];
            u[i] = u[i - 1];
        }
        if ('A' <= s[i] && s[i] <= 'Z')
            u[i]++;
        if ('a' <= s[i] && s[i] <= 'z')
            l[i]++;
    }
    int ans = u[(int) s.size() - 1];
    for (int i = 0; i < s.size(); i++) {
  //      cout << l[i] + u[(int) s.size() - 1] - u[i] << endl;
        ans = min(ans, l[i] + u[(int) s.size() - 1] - u[i]);
    }
    cout << ans << endl;
    return 0;
}