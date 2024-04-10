#include<iostream>
#include<cstring>
using namespace std;
int n, i, j, ii, mid, k, x;
char sol[105];
int nr[3], ff[200], viz[105];
struct str{
    int m;
    char s[102];
};
str v[3][10005];
struct str2{
    int p1, p2;
    char c1, c2;
};
str2 p[10005];
void calc(int t, int p, int u){
    cout<<"? "<< p <<" "<< u <<"\n";
    cout.flush();
    nr[t] = (u - p + 1) * (u - p + 2) / 2;
    for(i = 1; i <= nr[t]; i++){
        cin>> v[t][i].s + 1;
        v[t][i].m = strlen(v[t][i].s + 1);
    }
}
void solve(int t, int st, int dr){
    int n, i, j, jj, num;
    n = dr - st + 1;
    p[++k] = {st, dr, sol[st], sol[dr]};
    for(i = 2; i <= n / 2 + n % 2; i++){
        p[++k] = {st + i - 1, dr - i + 1, 0, 0};
        memset(ff, 0, sizeof(ff) );
        for(j = 1; j <= nr[t]; j++){
            if(v[t][j].m == i + 1){
                for(jj = 1; jj <= i + 1; jj++){
                    ff[ v[t][j].s[jj] ]++;
                }
            }
        }
        num = i;
        for(j = k - 1; j > k - i; j--){
            num--;
            ff[ p[j].c1 ] -= num;
            ff[ p[j].c2 ] -= num;
        }
        for(j = 'a'; j <= 'z'; j++){
            if(ff[j] % (i + 1) != 0){
                if(p[k].c1 == 0){
                    p[k].c1 = j;
                }
                else{
                    p[k].c2 = j;
                }
            }
        }
        if(p[k].c2 == 0){
            p[k].c2 = p[k].c1;
        }
        if(p[k].p1 == p[k].p2){
            sol[ p[k].p1 ] = p[k].c1;
        }
    }
}
int main(){
    cin>> n;
    if(n == 1){
        cout<<"? 1 1\n";
        cout.flush();
        cin>> sol + 1;
        cout<<"! "<< sol + 1;
        return 0;
    }
    mid = n / 2;
    calc(0, 1, n);
    calc(1, 1, mid);
    calc(2, mid, n);
    for(ii = 0; ii < 3; ii++){
        for(i = 1; i <= nr[ii]; i++){
            if(v[ii][i].m == 1){
                if(ii == 0){
                    ff[ v[ii][i].s[1] ]--;
                }
                else{
                    ff[ v[ii][i].s[1] ]++;
                }
            }
        }
    }
    for(i = 'a'; i <= 'z'; i++){
        if(ff[i] == 1){
            sol[mid] = i;
            break;
        }
    }
    memset(ff, 0, sizeof(ff) );
    for(i = 1; i <= nr[1]; i++){
        if(v[1][i].m == 2){
            ff[ v[1][i].s[1] ]++;
            ff[ v[1][i].s[2] ]++;
        }
    }
    ff[ sol[mid] ]--;
    for(i = 'a'; i <= 'z'; i++){
        if(ff[i] % 2 == 1){
            sol[1] = i;
            break;
        }
    }
    memset(ff, 0, sizeof(ff) );
    for(i = 1; i <= nr[2]; i++){
        if(v[2][i].m == 2){
            ff[ v[2][i].s[1] ]++;
            ff[ v[2][i].s[2] ]++;
        }
    }
    ff[ sol[mid] ]--;
    for(i = 'a'; i <= 'z'; i++){
        if(ff[i] % 2 == 1){
            sol[n] = i;
            break;
        }
    }
    solve(0, 1, n);
    solve(1, 1, mid);
    solve(2, mid, n);
    for(ii = 1; ii <= n; ii++){
        for(i = 1; i <= n; i++){
            if(sol[i] != 0 && viz[i] == 0){
                x = i;
                break;
            }
        }
        viz[x] = 1;
        for(i = 1; i <= k; i++){
            if(p[i].p1 == x){
                if(p[i].c1 == sol[x]){
                    sol[ p[i].p2 ] = p[i].c2;
                }
                else{
                    sol[ p[i].p2 ] = p[i].c1;
                }
            }
            if(p[i].p2 == x){
                 if(p[i].c1 == sol[x]){
                    sol[ p[i].p1 ] = p[i].c2;
                }
                else{
                    sol[ p[i].p1 ] = p[i].c1;
                }
            }
        }
    }
    cout<<"! "<< sol + 1;
}