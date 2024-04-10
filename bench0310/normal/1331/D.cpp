#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << ((int)(s.back()-'0')&1) << endl;
    return 0;
}