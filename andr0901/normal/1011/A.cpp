#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char prev = 'a' - 2;
    char curr = 'z';
    int ans = 0;
    string sa;
    for (int i = 0; i < k; i++) {
        bool f = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] > prev + 1 && s[j] <= curr) {
                curr = s[j];
                f = 1;
            }
            /*cout << i << " " << j << s[j] << "   " << curr << "    " << prev << endl;*/
        }
        if (f == 0) {
            cout << -1;
            return 0;
        }
        sa += curr;
        prev = curr;
        ans += curr - 'a' + 1;
        curr = 'z';
    }
    /*cout << sa;*/
    cout << ans;
    return 0;
}