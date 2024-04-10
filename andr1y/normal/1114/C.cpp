#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define mp make_pair
int binpow(int a, int b){
    if(b == 1) return a;
    if(b == 0) return 1;
    if(b%2==0) return binpow(a*a, b/2);
    if(b%2==1) return binpow(a*a, b/2)*a;
}
struct fact{
    array<int, 20> p;
    array<int, 20> l;
    pair<int, int> maxl;
    int pc = 0;
    void clearMe(){
        memset(begin(p), 0, sizeof(p));
        memset(begin(l), 0, sizeof(l));
    }
};
fact factorizate(int n){
    fact result;
    result.clearMe();
    int i = 2;
    while(n > 1 && i*i <= n){
        if(n%i==0){
            result.p[result.pc] = i;
            while(n%i==0){
                result.l[result.pc]++;
                n/=i;
            }
            if(result.maxl.x < result.l[result.pc]) result.maxl = mp(result.l[result.pc], result.pc);
            result.pc++;
        }
        i++;
    }
    if(result.pc == 0 || n!=1){
        result.p[result.pc] = n;
        result.l[result.pc] = 1;
        result.pc++;
    }
    return result;
}
main(){
    int a, k;
    cin >> a >> k;
    fact f = factorizate(k);
    int done = 0;
    int mres = LLONG_MAX;
    while(done != f.pc){
        int o = a;
        int oo = 0;
        while(o > 0){
            o/=f.p[done];
            oo += o;
        }
        mres = min(mres, oo/f.l[done]);
        done++;
    }
    cout << mres;
}