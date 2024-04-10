#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1000 * 1000 + 5;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int st = 0, k = 0, prev = -1;
    for(size_t i = 0; i < s.length(); i++) {
        if(st == 0) {
            if('a' <= s[i] && s[i] <= 'z')
                a[k]++;
            else if(('0' <= s[i] && s[i] <= '9') || s[i] == '_')
                continue;
            else if(s[i] == '@')
                st = 1;
            else
                a[k] = 0;
        }
        else if(st == 1) {
            if(('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')) {
                st = 2;
                prev = i - 1;
            }
            else {
                st = 0;
                a[k] = 0;
            }
        }
        else if(st == 2) {
            if(s[i] == '.')
                st = 3;
            else if(!('a' <= s[i] && s[i] <= 'z') && !('0' <= s[i] && s[i] <= '9')) {
                st = 0;
                a[k] = 0;
                i = prev;
            }
        }
        else if(st == 3) {
            b[k] = 0;
            for(size_t j = i; j < s.length(); j++)
                if(!('a' <= s[j] && s[j] <= 'z'))
                    break;
                else
                    b[k]++;
            if(!b[k])
                a[k] = 0;
            else
                k++;
            st = 0;
            i--;
        }
    }
    long long ans = 0;
    for(int i = 0; i < k; i++)
        ans += (long long)a[i] * b[i];
    cout << ans << '\n';
    return 0;
}