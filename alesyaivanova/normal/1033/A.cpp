#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ax, ay, bx, by, cx, cy;
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    if ((ax - bx) * (ax - cx) > 0 && (ay - by) * (ay - cy) > 0)
        cout << "YES";
    else
        cout << "NO";
}