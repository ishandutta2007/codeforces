#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<2*(n/7)+(n%7==6)<<' '<<2*(n/7)+min(2,n%7);
    return 0;
}