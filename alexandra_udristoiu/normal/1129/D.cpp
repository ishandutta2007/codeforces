#include<iostream>
#include<cmath>
#define DIM 100005
#define mod 998244353
using namespace std;
int n, k, i, ii, num, j, m, rad;
int v[DIM], r[DIM], a[DIM], d[DIM], s[320][640], st[320], dr[320], sa[DIM];
pair<int, int> w[DIM];
void update(int ii){
    int i, num = 0;
    for(i = 0; i <= rad + rad; i++){
        s[ii][i] = 0;
    }
    for(i = dr[ii]; i >= st[ii]; i--){
        num += a[i];
        s[ii][num + rad] = (s[ii][num + rad] + d[i - 1]) % mod;
    }
    sa[ii] = num;
    for(i = 1; i <= rad + rad; i++){
        s[ii][i] = (s[ii][i] + s[ii][i - 1]) % mod;
    }
}
int main(){
    cin>> n >> k;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    rad = sqrt(n * 1.0);
    m = n / rad;
    if(n % rad != 0){
        m++;
    }
    for(ii = 1; ii <= m; ii++){
        st[ii] = (ii - 1) * rad + 1;
        dr[ii] = min(st[ii] + rad - 1, n);
        for(i = st[ii]; i <= dr[ii]; i++){
            r[i] = ii;
        }
    }
    d[0] = 1;
    for(ii = 1; ii <= m; ii++){
        for(i = st[ii]; i <= dr[ii]; i++){
            if(w[ v[i] ].first != 0){
                a[ w[ v[i] ].first ] = 0;
                if(r[ w[ v[i] ].first ] != ii){
                    update(r[ w[ v[i] ].first ]);
                }
            }
            if(w[ v[i] ].second != 0){
                a[ w[ v[i] ].second ] = -1;
                if(r[ w[ v[i] ].second  ] != ii){
                    update(r[ w[ v[i] ].second ]);
                }
            }
            a[i] = 1;
            w[ v[i] ].first = w[ v[i] ].second;
            w[ v[i] ].second = i;
            num = 0;
            for(j = i; j >= st[ii]; j--){
                num += a[j];
                if(num <= k){
                    d[i] = (d[i] + d[j - 1]) % mod;
                }
            }
            for(j = ii - 1; j >= 1; j--){
                if(k - num >= -rad){
                    d[i] = (s[j][ rad + min(rad, k - num) ] + d[i]) % mod;
                }
                num += sa[j];
            }
        }
        update(ii);
    }
    cout<< d[n];
    return 0;
}