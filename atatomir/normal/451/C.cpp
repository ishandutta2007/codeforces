#include <iostream>

using namespace std;

long long t,ti,d1,d2,n,k,p,ok=0,maxim,v;

int check(long long s1,long long s2,long long s3){
    if (s1+s2+s3 > k) return 0;
    if ((k-s1-s2-s3)%3 != 0) return 0;

    maxim = s1;
    if (s2 > maxim) maxim = s2;
    if (s3 > maxim) maxim = s3;

    v = 3*maxim - s1 - s2 - s3;
    if (v > n-k) return 0;
    if ((n-k-v)%3 != 0 ) return 0;

    ok = 1;
    return 1;

}

int main()
{
    cin >> t;
    for(ti=1;ti<=t;ti++){
        cin >> n >> k >> d1 >> d2;
        ok = 0;

        check(d1,0,d2);
        check(d1+d2,d2,0);
        check(0,d1,d1+d2);
        p = d1; if (d2 > d1) p = d2;
        check(-d1+p,p,-d2+p);

        if(ok) cout << "yes\n"; else cout << "no\n";
    }


    return 0;
}