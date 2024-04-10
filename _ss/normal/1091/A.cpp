#include <iostream>

using namespace std;

int main()
{
    int y,b,r;
    cin>>y>>b>>r;
    if (y>=r-2 && b>=r-1) cout<<(r-1)*3;
    else if (y>=b-1 && r>=b+1) cout<<b*3;
    else cout<<(y+1)*3;
    return 0;
}