#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define DIM 400005
#define f first
#define s second
using namespace std;
int n, m, u, nr, i, ii, jj, x, sum, num, k, j;
int w[DIM];
pair<int, int> v[DIM];
vector<int> a[50000];
int main(){
    cin>> n;
    k = n;
    for(i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1);
    for(i = 1; i <= n; i++){
        if(w[i] != w[i - 1]){
            v[++nr] = make_pair(1, w[i]);
        }
        else{
            v[nr].f++;
        }
    }
    sort(v + 1, v + nr + 1);
    n = 0;
    num = nr;
    u = 1;
    for(i = 1; i <= k; i++){
        while(v[u].f == i){
            num--;
            sum += i;
            u++;
        }
        x = (sum + num * i) / i;
        if(x >= i){
            if(x * i > n * m){
                n = i;
                m = x;
            }
        }
    }
    for(i = nr; i >= 1; i--){
        v[i].f = min(v[i].f, n);
    }
    u = nr;
    for(i = 1; i <= n; i++){
        a[i].resize(m + 2);
    }
    for(i = 1; i <= m; i++){
        ii = 1;
        jj = i;
        while(ii <= n){
            if(v[u].f == 0){
                u--;
            }
            a[ii][jj] = v[u].s;
            v[u].f--;
            ii++;
            jj++;
            if(jj > m){
                jj = 1;
            }
        }
    }
    cout<< n * m <<"\n"<< n <<" "<< m <<"\n";
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cout<< a[i][j] <<" ";
        }
        cout<<"\n";
    }
}