#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a>0&&d>0&&a==d) cout << 1 << endl;
    else if(a==d&&c==0) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}