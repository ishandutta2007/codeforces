#include <iostream>

using namespace std;

int stiva[100005];
int sz;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++ i) {
        stiva[++ sz] = 1;

        while (sz > 1 && stiva[sz] == stiva[sz - 1])
            stiva[sz - 1] ++, sz --;
    }

    for (int i = 1; i <= sz; ++ i)
        cout << stiva[i] << " \n"[i == sz];

    return 0;
}