#include <iostream>

using namespace std;

long n,i,a[100005],decr=0,posi=1,posj=1,t;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++) cin >> a[i];
    a[n+1] = 1000000009;
    a[0] = - 1000000009 ;

    for(i=1;i<=n;i++){
        if(a[i] < a[i-1]) {
            if (decr) {
                cout << "no";
                return 0;
            }

            decr = 1;
            posi = i-1;
            while(a[i] > a[i+1]) i++;
            posj = i;

            t = a[posi]; a[posi] = a[posj]; a[posj] = t;

            if(a[posi-1] > a[posi]) {
                cout << "no";
                return 0;
            }
        }
    }

    cout << "yes\n" << posi << ' ' << posj;

    return 0;
}