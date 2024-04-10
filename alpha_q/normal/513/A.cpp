#include <iostream>

using namespace std;

main()
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    string res = "Second";
    if (n1 > n2) res = "First";
    cout << res;
}