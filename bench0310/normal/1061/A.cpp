#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long n,s;
    cin >> n >> s;
    cout << (s+n-1)/n << endl;
    return 0;
}