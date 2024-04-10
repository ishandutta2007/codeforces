#include <iostream>

using namespace std;

bool f(int t, int s, int x){
    if (x == t || x == t + 1)
        return 1;
    if (x < 0)
        return 0;
    return f(t, s, x - s);
}
int main (){
    int t, s, x;
    cin >> t >> s >> x;
    if (t > x || t + 1 == x)
        return cout << "NO", 0;
    if (x < s){
        if (x == t)
            return cout << "YES", 0;
        else
            return cout << "NO", 0;
    }
    if (f(t, s, x) == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}