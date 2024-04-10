#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 26;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int len = 0, cnt1 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        len += a[i];
        if(a[i] & 1)
            cnt1++;
    }
    if(n == 1) {
        cout << len << '\n';
        for(int i = 0; i < len; i++)
            cout << 'a';
        cout << '\n';
        return 0;
    }
    if(cnt1) {
        if(len & 1) {
            if(cnt1 >= 2) {
                cout << 0 << '\n';
                for(int i = 0; i < n; i++)
                    for(int j = 0; j < a[i]; j++)
                        cout << char('a' + i);
                cout << '\n';
            }
            else {
                int id = 0;
                while(!(a[id] & 1))
                    id++;
                int aid = a[id];
                for(int k = aid; k > 0; k -= 2) {
                    a[id] = aid - k;
                    bool bad = false;
                    for(int i = 0; i < n; i++)
                        if(a[i] % (2 * k)) {
                            bad = true;
                            break;
                        }
                    if(bad)
                        continue;
                    cout << k << '\n';
                    string s;
                    for(int i = 0; i < n; i++)
                        for(int j = 0; j < a[i] / (2 * k); j++)
                            s += char('a' + i);
                    for(int i = 0; i < k; i++) {
                        cout << char('a' + id) << s;
                        reverse(s.begin(), s.end());
                        cout << s;
                        reverse(s.begin(), s.end());
                    }
                    cout << '\n';
                    break;
                }
            }
        }
        else {
            cout << 0 << '\n';
            for(int i = 0; i < n; i++)
                for(int j = 0; j < a[i]; j++)
                    cout << char('a' + i);
            cout << '\n';
        }
        return 0;
    }
    for(int k = 1; k <= len; k++) {
        if(len % k)
            continue;
        int d = len / k;
        bool bad = false;
        for(int i = 0; i < n; i++)
            if(a[i] % d) {
                bad = true;
                break;
            }
        if(bad)
            continue;
        cout << d << '\n';
        string s;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < a[i] / d; j++)
                s += char('a' + i);
        for(int i = 0; i < d; i++) {
            cout << s;
            reverse(s.begin(), s.end());
        }
        cout << '\n';
        return 0;
    }
    return 0;
}