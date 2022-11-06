#include <iostream>
#include <iomanip>

using namespace std;

double n,m;

int main()
{
    cin >> n >> m;
    if(n==m && n==1) cout << 1.00; else
    cout << setprecision(10) << 1/n + ((n-1)/n)*((m-1)/(n*m-1));

    return 0;
}