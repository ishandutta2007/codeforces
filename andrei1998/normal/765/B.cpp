#include <iostream>
#include <string>

using namespace std;

bool freq[105];

int main()
{
    string str;
    cin >> str;

    char chr = 'a';
    for (auto it: str)
        if (!freq[it - 'a']) {
            if (it != chr) {
                cout << "NO\n";
                return 0;
            }
            chr ++;
            freq[it - 'a'] = true;
        }

    cout << "YES\n";
    return 0;
}