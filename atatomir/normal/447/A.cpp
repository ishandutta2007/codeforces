#include <iostream>

using namespace std;

long n,i,p,h[305],x;

int main()
{
    cin >> p >> n;
    for(i=1;i<=n;i++){
        cin >> x; x %= p;
        if(h[x]) {
            cout << i << '\n';
            return 0;
        }
        h[x]++;
    }
    cout << -1;
    return 0;
}