#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int x,y;
    int m=0;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        m=max(m,x+y);
    }
    cout << m << endl;
    return 0;
}