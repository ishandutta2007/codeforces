#include <bits/stdc++.h>

using namespace std;

int N, M;
int par[200005];
int mn[200005], mx[200005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int add(int x, int y){
    x = getrt(x), y = getrt(y);
    mn[x] = min(mn[x], mn[y]);
    mx[x] = max(mx[x], mx[y]);
    par[y] = x;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        par[i] = i;
        mn[i] = i, mx[i] = i;
    }
    for(int i = 1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        int n = getrt(i);
        int l = mn[n], r = mx[n];
        for(i = l; i<=r; i++){
            if(getrt(i) != getrt(n)){
                cnt++;
                add(n, i);
                n = getrt(n);
                r = mx[n];
            }
        }
        i--;
    }
    cout << cnt << endl;
}