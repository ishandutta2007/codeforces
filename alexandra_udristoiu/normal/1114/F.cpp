#include<iostream>
#define DIM 400005
#define mod 1000000007
using namespace std;
int n, q, i, j, nr, sol, st, dr, val, x;
long long x2, y2;
int p[305], c[305], v[DIM], invmod[305];
char t[15];
struct str{
    unsigned long long mnod, mlazy;
    int pnod, plazy;
};
str aint[4 * DIM], s;
void ff(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        long long x2, y2;
        ff(b, a % b, x2, y2);
        x = y2;
        y = x2 - a / b * y2;
    }
}
int mult(int x, int e){
    if(e == 0){
        return 1;
    }
    else{
        int a = mult(x, e / 2);
        if(e % 2 == 0){
            return a * 1LL * a % mod;
        }
        else{
            return a * 1LL * a % mod * x % mod;
        }
    }
}
void build(int nod, int st, int dr){
    if(st == dr){
        aint[nod].pnod = v[st];
        aint[nod].plazy = 1;
        for(int i = 1; i <= nr; i++){
            if(v[st] % p[i] == 0){
                aint[nod].mnod += (1LL << i);
            }
        }
    }
    else{
        int mid = (st + dr) / 2;
        build(2 * nod, st, mid);
        build(2 * nod + 1, mid + 1, dr);
        aint[nod].mnod = (aint[2 * nod].mnod | aint[2 * nod + 1].mnod);
        aint[nod].pnod = aint[2 * nod].pnod * 1LL * aint[2 * nod + 1].pnod % mod;
        aint[nod].plazy = 1;
    }
}
void update(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        aint[nod].mlazy |= s.mnod;
        aint[nod].plazy = aint[nod].plazy * 1LL * s.pnod % mod;
    }
    else{
        aint[2 * nod].plazy = aint[2 * nod].plazy * 1LL * aint[nod].plazy % mod;
        aint[2 * nod].mlazy |= aint[nod].mlazy;
        aint[2 * nod + 1].plazy = aint[2 * nod + 1].plazy * 1LL * aint[nod].plazy % mod;
        aint[2 * nod + 1].mlazy |= aint[nod].mlazy;
        aint[nod].plazy = 1;
        aint[nod].mlazy = 0;
        int mid = (st + dr) / 2;
        if(p <= mid){
            update(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            update(2 * nod + 1, mid + 1, dr, p, u);
        }
        aint[nod].mnod = (aint[2 * nod].mnod | aint[2 * nod].mlazy | aint[2 * nod + 1].mnod | aint[2 * nod + 1].mlazy);
        aint[nod].pnod = aint[2 * nod].pnod * 1LL * aint[2 * nod + 1].pnod % mod * mult(aint[2 * nod].plazy, mid - st + 1) % mod * mult(aint[2 * nod + 1].plazy, dr - mid) % mod;
    }
}
void query(int nod, int st, int dr, int p, int u){
    if(p <= st && dr <= u){
        s.mnod = (s.mnod | aint[nod].mnod | aint[nod].mlazy);
        s.pnod = s.pnod * 1LL * aint[nod].pnod % mod * mult(aint[nod].plazy, dr - st + 1) % mod;
    }
    else{
        aint[2 * nod].plazy = aint[2 * nod].plazy * 1LL * aint[nod].plazy % mod;
        aint[2 * nod].mlazy |= aint[nod].mlazy;
        aint[2 * nod + 1].plazy = aint[2 * nod + 1].plazy * 1LL * aint[nod].plazy % mod;
        aint[2 * nod + 1].mlazy |= aint[nod].mlazy;
        aint[nod].plazy = 1;
        aint[nod].mlazy = 0;
        int mid = (st + dr) / 2;
        if(p <= mid){
            query(2 * nod, st, mid, p, u);
        }
        if(u > mid){
            query(2 * nod + 1, mid + 1, dr, p, u);
        }
        aint[nod].mnod = (aint[2 * nod].mnod | aint[2 * nod].mlazy | aint[2 * nod + 1].mnod | aint[2 * nod + 1].mlazy);
        aint[nod].pnod = aint[2 * nod].pnod * 1LL * aint[2 * nod + 1].pnod % mod * mult(aint[2 * nod].plazy, mid - st + 1) % mod * mult(aint[2 * nod + 1].plazy, dr - mid) % mod;
    }
}
int main(){
    for(i = 2; i <= 300; i++){
        if(c[i] == 0){
            p[++nr] = i;
            for(j = i + i; j <= 300; j += i){
                c[j] = 1;
            }
        }
    }
    for(i = 1; i <= nr; i++){
        ff(p[i], mod, x2, y2);
        x2 %= mod;
        if(x2 < 0){
            x2 += mod;
        }
        invmod[i] = x2;
    }
    cin>> n >> q;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    build(1, 1, n);
    for(; q; q--){
        cin>> t + 1;
        cin>> st >> dr;
        if(t[1] == 'M'){
            cin>> x;
            s.pnod = x;
            s.mnod = 0;
            for(i = 1; i <= nr; i++){
                if(x % p[i] == 0){
                    s.mnod += (1LL << i);
                }
            }
            update(1, 1, n, st, dr);
        }
        else{
            s.pnod = 1;
            s.mnod = 0;
            query(1, 1, n, st, dr);
            sol = s.pnod;
            for(i = 1; i <= nr; i++){
                if( ( (s.mnod >> i) & 1) == 1){
                    sol = sol * 1LL * (p[i] - 1) % mod * invmod[i] % mod;
                }
            }
            cout<< sol <<"\n";
        }
    }
    return 0;
}