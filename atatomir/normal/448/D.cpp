#include <iostream>

using namespace std;

long long n,m,k,i,j,mij,v1,v2;

inline long long sum(long long x) {
    long i;
    long long rez=0,loc;
    for(i=1;i<=n;i++) {
        loc = x / i;
        if (loc > m) loc = m;
        rez += loc;
    }
    return rez;
}

int main()
{
    cin >> n >> m >> k ;

    i = 1; j = n*m;
    do {
        mij = (i+j)/2;
        v1 = sum(mij-1)+1;
        v2 = sum(mij);

        if (k < v1)
            j = mij-1;
        else
        if (k > v2)
            i = mij+1;
        else
        {
            cout << mij;
            return 0;
        }

    }   while (i <= j);

    return 0;
}