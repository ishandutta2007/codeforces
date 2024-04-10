#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int brd[1000][1000];
long long ans[2000]; // y-x = -(n-1) ~ (m-1)
long long tot;
long long get_ans(int d){
    long long ret = 0, cur = 0;
    for(int i=0;i<n;i++){
        int tmp = i+d;
        if(0<=tmp && tmp<m){
            if(brd[i][tmp]) cur++;
            else{
                ret += cur*(cur-1)/2;
                cur=0;
            }
        }
        tmp++;
        if(0<=tmp && tmp<m){
            if(brd[i][tmp]) cur++;
            else{
                ret += cur*(cur-1)/2;
                cur=0;
            }
        }
    }
    ret += cur*(cur-1)/2;
    return ret;
}
void init(){
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) brd[i][j] = 1;
    tot = m*n;
    for(int d=-(n-1);d<(m-1);d++){
        // stair with d & d+1. i=0 to n-1
        ans[d+n] = get_ans(d);
        tot += ans[d+n];
    }
}
void print_ans(){
    for(int d=-(n-1);d<(m-1);d++) cout << ans[d+n] << " ";
}
void query(){
    int a,b;
    cin >> a >> b;
    a--;b--;
    if(brd[a][b]) tot--;
    else tot++;
    brd[a][b] = !brd[a][b];
    int dd = b-a;
    if(dd-1 >= -(n-1)){
        tot -= ans[dd-1+n];
        ans[dd-1+n] = get_ans(dd-1);
        tot += ans[dd-1+n];
    }
    if(dd < (m-1)){
        tot -= ans[dd+n];
        ans[dd+n] = get_ans(dd);
        tot += ans[dd+n];
    }
    cout << tot << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    init();
    for(int i=0;i<q;i++) query();
}