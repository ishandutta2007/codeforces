#include <iostream>

using namespace std;
int a, b, c, d;
int main()
{
    cin >> a >> b >> c;
    d=b-a;
    if(d==0) {
        cout << "YES" << endl;
        return 0;
    }
    if(c<0) {
        c*=-1;
        d*=-1;
    }
    if(c==0) {
        cout << "NO" << endl;
        return 0;
    }
    if(d%c==0 && d>0) {
        cout << "YES" << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        return 0;
    }
    return 0;
}