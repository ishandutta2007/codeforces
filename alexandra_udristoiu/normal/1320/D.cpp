#include<iostream>
#define DIM 200005
#define mod1 1986443
#define mod2 1000000009
#define f first
#define s second
using namespace std;
int n, q, i, x, y, j, len, u, ok;
char s[DIM];
int num[DIM];
pair<int, int> h[DIM][2], pt[DIM];
pair<int, int> calc(int p, int u, int t){
    pair<int, int> val = h[u][t];
    val.f -= h[p - 1][t].f * 1LL * pt[ num[u] - num[p - 1] ].f % mod1;
    if(val.f < 0){
        val.f += mod1;
    }
    val.s -= h[p - 1][t].s * 1LL * pt[ num[u] - num[p - 1] ].s % mod2;
    if(val.s < 0){
        val.s += mod2;
    }
    return val;
}
int main(){
    cin>> n;
    cin>> s + 1;
    for(i = 1; i <= n; i++){
        if(s[i] == '0'){
            num[i] = num[i - 1] + 1;
            h[i][0].f = (h[i - 1][0].f * 2 + i % 2) % mod1;
            h[i][0].s = (h[i - 1][0].s * 2 + i % 2) % mod2;
            h[i][1].f = (h[i - 1][1].f * 2 + 1 - i % 2) % mod1;
            h[i][1].s = (h[i - 1][1].s * 2 + 1 - i % 2) % mod2;
        }
        else{
            num[i] = num[i - 1];
            h[i][0] = h[i - 1][0];
            h[i][1] = h[i - 1][1];
        }
    }
    pt[0] = make_pair(1, 1);
    for(i = 1; i <= n; i++){
        pt[i].f = pt[i - 1].f * 2 % mod1;
        pt[i].s = pt[i - 1].s * 2 % mod2;
    }
    cin>> q;
    for(; q; q--){
        cin>> x >> y >> len;
        if(num[x + len - 1] - num[x - 1] == num[y + len - 1] - num[y - 1]){
            if(calc(x, x + len - 1, x % 2) == calc(y, y + len - 1, y % 2) ){
                cout<<"Yes\n";
                continue;
            }
        }
        cout<<"No\n";
    }
}