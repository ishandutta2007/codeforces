#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 77;
int ans , n , v , a[N] , p[N];
long long t[N] , c[N] , d[N];
int cc[N] , dd[N];
vector < long long > u1 , u2;
int fen[N];
void upd(int x , int val) {
    for(;x < N;x += x & - x)
        if(fen[x] < val)
            fen[x] = val;
}
int get(int x) {
    int r = -1e9;
    for(;x;x -= x & - x)
        if(r < fen[x])
            r = fen[x];
    return r;
}
void test() {
    scanf("%d %d" , & n , & v);
    for(int i = 1;i <= n;++ i)
        scanf("%lld" , t + i) , t[i] *= v;
    ++ n;
    for(int i = 1;i <= n;++ i) {
        if(i != n) scanf("%d" , a + i);
        c[i] = a[i] + t[i];
        d[i] = t[i] - a[i];
        u1.push_back(c[i]);
        u2.push_back(d[i]);
    }
    sort(u1.begin() , u1.end());
    u1.resize(unique(u1.begin() , u1.end()) - u1.begin());
    sort(u2.begin() , u2.end());
    u2.resize(unique(u2.begin() , u2.end()) - u2.begin());
    for(int i = 1;i <= n;++ i) {
        p[i] = i;
        cc[i] = lower_bound(u1.begin() , u1.end() , c[i]) - u1.begin() + 1;
        dd[i] = lower_bound(u2.begin() , u2.end() , d[i]) - u2.begin() + 1;
        //cout << c[i] << ' ' << d[i] << ' ' << cc[i] << ' ' << dd[i] << endl;
    }
    sort(p + 1 , p + 1 + n , [&](int x , int y) { return make_pair(cc[x] , dd[x]) < make_pair(cc[y],dd[y]);});
    memset(fen , -63 , sizeof fen);
    for(int i = 1;i <= n;++ i) {
        int id = p[i];
        int bs = get(dd[id]);
        if(id == n) bs = 0;
        upd(dd[id] , bs + 1);
        if(ans < bs + 1)
            ans = bs + 1;
    }
    printf("%d" , ans - 1);

}

int main() {
    int tst = 1;
    while(tst --)
        test();
    return 0;
}