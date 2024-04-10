#include <iostream>

using namespace std;

int prime;

int main()
{
    long long b;
    cin >> b;
    int cnt=0;
    for(long long i=1;i*i<=b;i++)
    {
        if((!(b%i))&&(i*i<b)) cnt+=2;
        if((!(b%i))&&(i*i==b)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}