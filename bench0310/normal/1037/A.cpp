#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(1)
    {
        n++;
        if((n&(n-1))==0) break;
    }
    int cnt=0;
    while(n>1)
    {
        n/=2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}