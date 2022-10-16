#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

string s;
char b[4];
int n;

int mod(int k) {
    int res = 0;
    for(int i = 0; i < n; i++)
        res = (res * 10 + (s[i] - '0')) % k;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    int k = 1;
    for(int i = 0; i < n; i++)
        if(s[i] == '1' && !b[0]) {
            swap(s[i], s[n - k]);
            s[n - k] = '0';
            k++;
            b[0] = true;
            i--;
        }
        else if(s[i] == '6' && !b[1]) {
            swap(s[i], s[n - k]);
            s[n - k] = '0';
            k++;
            b[1] = true;
            i--;
        }
        else if(s[i] == '8' && !b[2]) {
            swap(s[i], s[n - k]);
            s[n - k] = '0';
            k++;
            b[2] = true;
            i--;
        }
        else if(s[i] == '9' && !b[3]) {
            swap(s[i], s[n - k]);
            s[n - k] = '0';
            k++;
            b[3] = true;
            i--;
        }
    bool bb = false;
    for(int i = 0; i < n; i++)
        if(s[i] != '0') {
            swap(s[0], s[i]);
            bb = true;
            break;
        }
    if(!bb) {
        s.resize(n - 4);
        cout << 1869 << s << '\n';
        return 0;
    }
    int m = mod(7);
    s.resize(n - 4);
    cout << s;
    if(m == 0)
        cout << 1869 << '\n';
    else if(m == 1)
        cout << 1896 << '\n';
    else if(m == 2)
        cout << 1986 << '\n';
    else if(m == 3)
        cout << 1698 << '\n';
    else if(m == 4)
        cout << 6198 << '\n';
    else if(m == 5)
        cout << 1689 << '\n';
    else if(m == 6)
        cout << 1968 << '\n';
    return 0;
}