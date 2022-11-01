#include <iostream>

using namespace std;

int main()
{
    int b,k;
    cin >> b >> k;
    int a[k];
    for(int i=0;i<k;i++) cin >> a[i];
    if(!(b&1))
    {
        if(!(a[k-1]&1)) cout << "even" << endl;
        else cout << "odd" << endl;
    }
    else
    {
        int sum=0;
        for(int i=0;i<k;i++) sum+=a[i];
        if(!(sum&1)) cout << "even" << endl;
        else cout << "odd" << endl;
    }
    return 0;
}