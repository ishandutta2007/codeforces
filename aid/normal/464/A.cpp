#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, p;
    string s;
    cin >> n >> p >> s;
    for(int i = n - 1; i >= 0; i--) {
        for(char j = s[i] + 1; j < 'a' + p; j++)
            if((!i || s[i - 1] != j) && (i <= 1 || s[i - 2] != j)) {
                s[i] = j;
                for(int k = i + 1; k < n; k++)
                    for(char l = 'a'; l < 'a' + p; l++)
                        if(s[k - 1] != l && (k <= 1 || s[k - 2] != l)) {
                            s[k] = l;
                            break;
                        }
                cout << s << '\n';
                return 0;
            }
    }
    cout << "NO\n";
    return 0;
}