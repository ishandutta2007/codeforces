#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string str;

    cin >> n >> str;

    int a = 0, d = 0;

    for (auto it: str)
        if (it == 'A')
            ++ a;
        else
            ++ d;

    if (a == d)
        cout << "Friendship\n";
    else if (a > d)
        cout << "Anton\n";
    else
        cout << "Danik\n";

    return 0;
}