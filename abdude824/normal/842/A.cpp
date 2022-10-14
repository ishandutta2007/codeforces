#include <bits/stdc++.h>

using namespace std;

long long a,b,c,d,e;

int main()
{
    cin >> a >> b >> c >> d >> e;
    for(int i = c; i <= d; ++i){
        if(i * e >= a && i * e <= b){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}