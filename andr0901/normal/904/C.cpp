#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <char> a(26);
    for (int i = 0; i <= 25; i++) a[i] = i + 'a';
    bool t = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        for (int j = 0; j < 26; j++) if (a[j] == 1) k++;
        if(k == 25) t = 1;
        char x;
        cin >> x;
        string y;
        cin >> y;
        if (x == '?') {
            a[y[0] - (int)'a'] = 1;
            if(t == 1) s++;
        }
        else if (x == '.') {
            for (int j = 0; j < y.size(); j++) a[y[j] - (int)'a'] = 1;
        }
        else if (x == '!') {
            if (t == 1) s++;
            for (int j = 0; j < 26; j++) {
                int l = 0;
                for (int r = 0; r < y.size(); r++) if (a[j] != y[r]) l++;
                if (l == y.size()) a[j] = 1;
            }
        }
    }
    if (s == 0) cout << 0;
    else cout << s - 1;
    return 0;
}