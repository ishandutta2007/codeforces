#include <iostream>

using namespace std;

long n,m,days;

int main()
{
    cin >> n >> m;

    while(n) {
        if(n < m) {
            days += n;
            n = 0;
        } else {
            n -= m-1;
            days += m;
        }
    }

    cout << days;

    return 0;
}