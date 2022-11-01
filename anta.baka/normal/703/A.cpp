#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int f = 0, s = 0;
    for(int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        if(a > b)
            f++;
        else if(a < b)
            s++;
    }
    if(f > s)
        cout << "Mishka";
    else if(s > f)
        cout << "Chris";
    else
        cout << "Friendship is magic!^^";
    return 0;
}