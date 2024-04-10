#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int k=min(n,m);

    if(k%2==0)
        cout<<"Malvika\n";
    else
        cout<<"Akshat\n";

    return 0;
}