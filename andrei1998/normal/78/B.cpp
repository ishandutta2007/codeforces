#include <iostream>
#include <string>

using namespace std;

char cols[] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};

int main()
{
    int n;
    cin >> n;

    string str;
    str.resize(n);

    for (int i = 0; i < n; ++ i)
        str[i] = cols[i % 4];

    if (n > 3) {
        str[0] = 'B';
        str[1] = 'I';
        str[2] = 'V';
    }

    cout << str << '\n';
    return 0;
}