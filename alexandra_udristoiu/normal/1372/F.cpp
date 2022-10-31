#include<iostream>
#include<algorithm>
using namespace std;
int n, i, nr, j;
int v[200005];
struct str{
    int val, num;
};
str w[25005];
void query(int p, int u, int &x, int &num){
    cout<<"? "<< p <<" "<< u <<"\n";
    cout.flush();
    cin>> x >> num;
}
void solve(int p, int u){
    if(p > u){
        return;
    }
    int i, pt, x, num, ii, jj, x2, num2, x3, num3, p2, u2;
    query(p, u, x, num);
    w[++nr] = {x, num};
    pt = 1;
    while(pt * 2 <= num){
        pt *= 2;
    }
    ii = jj = 0;
    for(i = p; i <= u; i++){
        if(i % pt == 0){
            if(v[i] == 0){
                query(i, i, x2, num2);
                v[i] = x2;
            }
            if(v[i] == x){
                if(ii == 0){
                    ii = i;
                }
                else{
                    jj = i;
                }
            }
        }
    }
    if(jj == 0){
        query(ii - pt + 1, ii, x2, num2);
        if(x2 == x){
            p2 = ii - num2 + 1;
            u2 = p2 + num - 1;
        }
        else{
            query(ii, min(ii + pt - 1, n), x2, num2);
            u2 = ii + num2 - 1;
            p2 = u2 - num + 1;
        }
    }
    else{
        query(ii - pt + 1, jj, x2, num2);
        p2 = jj - num2 + 1;
        u2 = p2 + num - 1;
    }
    solve(p, p2 - 1);
    solve(u2 + 1, u);
}
int cmp(str a, str b){
    return a.val < b.val;
}
int main(){
    cin>> n;
    solve(1, n);
    sort(w + 1, w + nr + 1, cmp);
    cout<<"! ";
    for(i = 1; i <= nr; i++){
        for(j = 1; j <= w[i].num; j++){
            cout<< w[i].val <<" ";
        }
    }
}