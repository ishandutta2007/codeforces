#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int x=1,y=2,z=3;
    while((x+1)<=a&&(y+1)<=b&&(z+1)<=c)
    {
        x++;
        y++;
        z++;
    }
    cout << x+y+z << endl;
    return 0;
}