#include <iostream>

using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<a*b+b*c+c*a-a-b-c+1;
    return 0;
}