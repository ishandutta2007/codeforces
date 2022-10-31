#include<iostream>
#include<vector>
#define DIM 1000005
#define f first
#define s second
using namespace std;
int n, m, i, j, st, dr, mid, p, u, iv, jv, dir;
vector<char> a[DIM], sol[DIM];
vector<int> d1[DIM], d2[DIM];
pair<int, int> c[5 * DIM];
int di[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dj[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
int verif(int t){
    p = 1;
    u = 0;
    for(i = 0; i <= n + 1; i++){
        for(j = 0; j <= m + 1; j++){
            d1[i][j] = d2[i][j] = 0;
            if(a[i][j] != 'X'){
                c[++u] = make_pair(i, j);
                d1[i][j] = 1;
            }
        }
    }
    while(p <= u){
        for(dir = 0; dir < 8; dir++){
            iv = c[p].f + di[dir];
            jv = c[p].s + dj[dir];
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m && d1[iv][jv] == 0){
                d1[iv][jv] = d1[ c[p].f ][ c[p].s ] + 1;
                c[++u] = make_pair(iv, jv);
            }
        }
        p++;
    }
    p = 1;
    u = 0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(d1[i][j] > t){
                c[++u] = make_pair(i, j);
                d2[i][j] = 1;
            }
        }
    }
    while(p <= u){
        for(dir = 0; dir < 8; dir++){
            iv = c[p].f + di[dir];
            jv = c[p].s + dj[dir];
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m && d2[iv][jv] == 0){
                d2[iv][jv] = d2[ c[p].f ][ c[p].s ] + 1;
                c[++u] = make_pair(iv, jv);
            }
        }
        p++;
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a[i][j] == 'X' && (d2[i][j] > t || d2[i][j] == 0) ){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    cin>> n >> m;
    for(i = 0; i <= n + 1; i++){
        a[i].resize(m + 2);
        //sol[i].resize(m + 2);
        d1[i].resize(m + 2);
        d2[i].resize(m + 2);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin>> a[i][j];
        }
    }
    st = 1;
    dr = min(n, m);
    while(st <= dr){
        mid = (st + dr) / 2;
        if( verif(mid) ){
            st = mid + 1;
        }
        else{
            dr = mid - 1;
        }
    }
    cout<< dr - 1 <<"\n";
    verif(dr);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(d1[i][j] > dr){
                cout<<'X';
            }
            else{
                cout<<'.';
            }
        }
        cout<<"\n";
    }
}