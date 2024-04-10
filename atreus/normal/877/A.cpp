#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int cnt = 0;
    if (s.size() > 5)
        for (int i = 0; i <= s.size() - 6; i++)
            if (s.substr(i, 6) == "Nikita")
                cnt ++;
    if (s.size() > 4)
        for (int i = 0; i <= s.size() - 5; i++){
            if (s.substr(i, 5) == "Danil")
                cnt ++;
            if (s.substr(i, 5) == "Slava")
                cnt ++;
        }
    if (s.size() > 3)
        for (int i = 0; i <= s.size() - 4; i++)
            if (s.substr(i, 4) == "Olya")
                cnt ++;
    if (s.size() > 2)
        for (int i = 0; i <= s.size() - 3; i++)
            if (s.substr(i, 3) == "Ann")
                cnt ++;
    if (cnt == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}