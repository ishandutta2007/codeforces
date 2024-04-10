#include <iostream>

using namespace std;

long n,i,a[100005],sol=0;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> a[i];
    }
    a[0] = a[n];
    for(i=1;i<=n;i++)
        if(a[i-1] > a[i])
            if(!sol)
                sol = i;
            else{
                sol = -1;
                break;
            }

    if(sol == 0) sol = 1;

    if(sol == -1)
        cout << -1;
    else
        cout << (n-sol+1)%n;

    return 0;
}