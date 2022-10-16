#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    int longest_out = 0;
    int cnt_int = 0;

    bool open = false;
    int cnt = 0;
    for (int i = 0; i < str.size(); ++ i)
        if (str[i] == '(') {
            open = true;
            cnt = 0;
        }
        else if (str[i] == ')') {
            open = false;
            cnt = 0;
        }
        else if (isalpha(str[i])) {
            ++ cnt;
            if (i == 0 || !isalpha(str[i - 1])) {
                if (open)
                    ++ cnt_int;
            }

            if (!open) {
                if (cnt > longest_out)
                    longest_out = cnt;
            }
        }
        else
            cnt = 0;

    cout << longest_out << ' ' << cnt_int << '\n';
    return 0;
}