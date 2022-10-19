#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        int prev = -1;
        int tot = 0;
        for (int i = 0; i < 2 * n; i++) {
            int cur = 0;
            if (s[i] == '(') {
                cur = cnt;
                cnt++;
            }
            else {
                cnt--;
                cur = cnt;
            }
            if (cur > prev) tot++;



            
            prev = cur;
        }
        cout << tot << endl;
    }
}