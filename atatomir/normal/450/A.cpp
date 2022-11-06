#include <iostream>

using namespace std;

long n,m,i,a[105],last,ram;

int main()
{
    cin >> n >> m;
    for(i=1;i<=n;i++) cin >> a[i];
    ram = n;

    while (ram > 0) {
        for(i=1;i<=n;i++){
            if(a[i] > 0) {
                last = i;
                a[i] -= m;
                if (a[i] <= 0) ram--;
            }
        }
    }

    cout << last;

    return 0;
}