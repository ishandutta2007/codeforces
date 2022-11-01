#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp;
    int pos=0,neg=0;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        if(temp>0) pos++;
        if(temp<0) neg++;
    }
    if(pos>=neg&&pos>=(n+1)/2) cout << 5 << endl;
    else if(pos<neg&&neg>=(n+1)/2) cout << -5 << endl;
    else cout << 0 << endl;
    return 0;
}