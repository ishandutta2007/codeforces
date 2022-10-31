#include<iostream>
#include<cstring>
using namespace std;
int n, m, k, i, ii, jj, sol, in, jn, j;
char s[1005], a[55], b[55], aux[55];
int d[1005][52][52], a2[55][27], b2[55][27];
void update(int i, int ii, int jj, int cr){
    int val = 0;
    if(ii == n){
        ii = in;
        val++;
    }
    if(jj == m){
        jj = jn;
        val--;
    }
    d[i][ii][jj] = max(d[i][ii][jj], cr + val);
}
int main(){
    cin>> s + 1;
    k = strlen(s + 1);
    cin>> a + 1;
    n = strlen(a + 1);
    cin>> b + 1;
    m = strlen(b + 1);
    for(i = n - 1; i >= 1; i--){
        for(ii = 1, jj = n - i + 1; jj <= n; ii++, jj++){
            if(a[ii] != a[jj]){
                break;
            }
        }
        if(jj == n + 1){
            in = i;
            break;
        }
    }
    for(i = m - 1; i >= 1; i--){
        for(ii = 1, jj = m - i + 1; jj <= m; ii++, jj++){
            if(b[ii] != b[jj]){
                break;
            }
        }
        if(jj == m + 1){
            jn = i;
            break;
        }
    }

    for(i = 1; i <= n; i++){
        aux[i] = a[i];
    }
    for(i = n; i >= 1; i--){
        for(j = 0; j < 26; j++){
            aux[i] = j + 'a';
            for(ii = 1; ii <= i + 1; ii++){
                for(jj = ii; jj <= i; jj++){
                    if(aux[jj] != a[jj - ii + 1]){
                        break;
                    }
                }
                if(jj == i + 1){
                    a2[i - 1][j] = i - ii + 1;
                    break;
                }
            }
        }
    }

     for(i = 1; i <= m; i++){
        aux[i] = b[i];
    }
    for(i = m; i >= 1; i--){
        for(j = 0; j < 26; j++){
            aux[i] = j + 'a';
            for(ii = 1; ii <= i + 1; ii++){
                for(jj = ii; jj <= i; jj++){
                    if(aux[jj] != b[jj - ii + 1]){
                        break;
                    }
                }
                if(jj == i + 1){
                    b2[i - 1][j] = i - ii + 1;
                    break;
                }
            }
        }
    }

    for(i = 0; i <= k; i++){
        for(ii = 0; ii < n; ii++){
            for(jj = 0; jj < m; jj++){
                d[i][ii][jj] = -1000000;
            }
        }
    }
    d[0][0][0] = 0;
    for(i = 0; i < k; i++){
        for(ii = 0; ii < n; ii++){
            for(jj = 0; jj < m; jj++){
                if(s[i + 1] != '*'){
                    update(i + 1, a2[ii][ s[i + 1] - 'a' ], b2[jj][ s[i + 1] - 'a' ], d[i][ii][jj]);
                }
                else{
                    for(j = 0; j < 26; j++){
                        update(i + 1, a2[ii][j], b2[jj][j], d[i][ii][jj]);
                    }
                }
            }
        }
    }
    sol = -1000000;
    for(ii = 0; ii < n; ii++){
        for(jj = 0; jj < m; jj++){
            sol = max(sol, d[k][ii][jj]);
        }
    }
    cout<< sol;
}