#include<iostream>
#include<algorithm>
#define f first
#define s second
using namespace std;
int n, t, i, ii, jj, k, nr2;
int d[80][80][80], sol1[80], sol2[80], ind[80];
pair<int, int> v[80], pv[80][80][80];
pair< pair<int, int>, int> w[80];
void drum(int i, int ii, int jj){
    if(i == 0){
        return;
    }
    if(pv[i][ii][jj].f == ii - 1){
        sol1[ii] = ind[i];
    }
    if(pv[i][ii][jj].s == jj - 1){
        sol2[++nr2] = ind[i];
    }
    drum(i - 1, pv[i][ii][jj].f, pv[i][ii][jj].s);
}
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n >> k;
        for(i = 1; i <= n; i++){
            cin>> v[i].s >> v[i].f;
            w[i].f = v[i];
            w[i].s = i;
        }
        sort(w + 1, w + n + 1);
        for(i = 1; i <= n; i++){
            v[i] = w[i].f;
            ind[i] = w[i].s;
        }
        for(ii = 0; ii <= n; ii++){
            for(jj = 0; jj <= n; jj++){
                d[0][ii][jj] = -1000000000;
            }
        }
        d[0][0][0] = 0;
        for(i = 1; i <= n; i++){
            for(ii = 0; ii <= k; ii++){
                for(jj = 0; jj <= n - k; jj++){
                    d[i][ii][jj] = d[i - 1][ii][jj];
                    pv[i][ii][jj] = make_pair(ii, jj);
                    if(ii != 0 && d[i - 1][ii - 1][jj] + v[i].s + (ii - 1) * v[i].f > d[i][ii][jj]){
                        d[i][ii][jj] = d[i - 1][ii - 1][jj] + v[i].s + (ii - 1) * v[i].f;
                        pv[i][ii][jj] = make_pair(ii - 1, jj);
                    }
                    if(jj != 0 && d[i - 1][ii][jj - 1] + (k - 1) * v[i].f > d[i][ii][jj]){
                        d[i][ii][jj] = d[i - 1][ii][jj - 1] + (k - 1) * v[i].f;
                        pv[i][ii][jj] = make_pair(ii, jj - 1);
                    }
                }
            }
        }
        nr2 = 0;
        drum(n, k, n - k);
        cout<< k + nr2 * 2 <<"\n";
        for(i = 1; i < k; i++){
            cout<< sol1[i] <<" ";
        }
        for(i = 1; i <= nr2; i++){
            cout<< sol2[i] <<" -"<< sol2[i] <<" ";
        }
        cout<< sol1[k] <<"\n";
    }
}