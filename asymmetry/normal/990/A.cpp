#include <iostream>

using namespace std;

long long n, m, a, b, w;

int main()
{
    cin>>n>>m>>a>>b;
    w=min((m-(n%m))*a, (n%m)*b);
    cout<<w;
    return 0;
}