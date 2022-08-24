#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, m, s;
    cin >> n;
    cin >> m;
    cin >> s;
    int bazinga = (abs(n) + abs(m));
    if (bazinga % 2 == s % 2)
    {
        if ((abs(n) + abs(m)) <= s)
            cout << "Yes";
        else
            cout << "No";
    }
    else
    {
        cout << "No";
    }
    return 0;
}