#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x,y,z,stairs,elevator,doors;
    cin >> x >> y >> z >> stairs >> elevator >> doors;
    int elevate,walk;
    //if(x==z) elevate=2*doors+abs(x-y)*elevator;
    /*else*/ elevate=3*doors+abs(x-z)*elevator+abs(x-y)*elevator;
    walk=abs(x-y)*stairs;
    if(elevate<=walk) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}