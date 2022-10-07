#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif 
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll p, q, b;
        scanf("%lld%lld%lld", &p, &q, &b);
        ll tmp = __gcd(p, q);
        p /= tmp;
        q /= tmp;
        for (int j = 0; j < 100; j++) {
            tmp = __gcd(b, q);
            if (tmp == 1) {
                break;
            }
            //cerr << "tmp q:" <<q << " " << tmp << endl;
            for (;q % tmp == 0; q /= tmp);
        }
        if (q == 1) {
            puts("Finite");
        }
        else {
            puts("Infinite");
        }


    }


}