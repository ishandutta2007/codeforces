#include <bits/stdc++.h>

using namespace std;

int par[150005];
int dsulft[150005], dsurht[150005], lft[150005], rht[150005];
int N;

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin >> N;
    for(int i = 1; i<=N; i++){
        dsulft[i] = lft[i] = i;
        dsurht[i] = rht[i] = i;
        par[i] = i;
    }
    int T = N-1;
    while(T--){
        int a, b;
        cin >> a >> b;
        int rta = getrt(a), rtb = getrt(b);
        int l = dsulft[rtb], r = dsurht[rta];
        rht[r] = l;
        lft[l] = r;
        dsulft[rtb] = dsulft[rta];
        par[rta] = rtb;
    }
    int s = 0;
    for(int i = 1; i<=N; i++){
        if(lft[i] == i){
            s = i;
            break;
        }
    }
    printf("%d ", s);
    while(rht[s] != s){
        s = rht[s];
        printf("%d ", s);
    }
}