#include <iostream>
using namespace std;

int main()
{
    string a;
    cin >> a;

    string b = "CODEFORCES";

    int iCarDebA = 0, iCarDebB = 0;
    while(iCarDebA != (int)a.size() && iCarDebB != (int)b.size() && a[iCarDebA] == b[iCarDebB])
    {
        iCarDebA++;
        iCarDebB++;
    }

    int iCarFinA = (int)a.size() - 1, iCarFinB = (int)b.size() - 1;
    while(iCarFinA != -1 && iCarFinB != -1 && a[iCarFinA] == b[iCarFinB])
    {
        iCarFinA--;
        iCarFinB--;
    }

    if(iCarFinB < iCarDebB)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}