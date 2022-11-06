#include <iostream>

using namespace std;

long long n,m,k,maxim = 0;

void verif(long long n,long long m,long long k) {
    long long rez;
    if (k > n-1)
        verif(m,1,k-n+1);
    else {
        rez =  m * (n / (k+1));
        if (rez > maxim) maxim = rez;
    }
}

int main()
{
    cin >> n >> m >> k;

    if (k > n+m-2) {
        cout << "-1";
        return 0;
    }
    else {
        verif(n,m,k);
        verif(m,n,k);
    }

    cout << maxim;

    return 0;
}