#include <iostream>
using namespace std;

string a, b;

bool comparer(int da, int fa, int db, int fb)
{
    if(da + 1 == fa)
        return (a[da] == b[db]);
    
    bool egal = true;
    for(int iCar = 0;iCar < (fa - da);iCar++)
        if(a[da + iCar] != b[db + iCar])
            egal = false;
    
    if(egal)
        return true;
    
    if((fa - da) % 2 == 1)
        return false;
    
    int ma = (da + fa) / 2;
    int mb = (db + fb) / 2;
    return (comparer(da, ma, mb, fb) && comparer(ma, fa, db, mb)) || (comparer(da, ma, db, mb) && comparer(ma, fa, mb, fb));
}

int main()
{
    cin.sync_with_stdio(false);
    
    cin >> a >> b;
    
    if(comparer(0, a.size(), 0, b.size()))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}