#include <iostream>

using namespace std;

int main()
{
    int n,x,y,a,c=0;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(a<=x) c++;
    }
    if(x<=y) cout << (c+1)/2 << endl;
    else cout << n << endl;
    return 0;
}