#include <bits/stdc++.h>

using namespace std;

int T, N, M, X, Y;
int par[200005];
int msk[200005];
int sz[200005];

int getrt(int x){
    return par[x] = (par[x] == x ? x : getrt(par[x]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M >> X >> Y;
        for(int i = 1; i<=N; i++){
            par[i] = i;
            sz[i] = 1;
            msk[i] = 0;
        }
        msk[X] = 1;
        msk[Y] = 2;
        sz[X] = sz[Y] = 0;
        while(M--){
            int a, b;
            cin >> a >> b;
            if((a == X && b == Y) || (a == Y && b == X)){
                continue;
            }
            else if(a == X){
                msk[getrt(b)] |= 1;
            }
            else if(b == X){
                msk[getrt(a)] |= 1;
            }
            else if(a == Y){
                msk[getrt(b)] |= 2;
            }
            else if(b == Y){
                msk[getrt(a)] |= 2;
            }
            else if(getrt(a) != getrt(b)){
                msk[getrt(b)] |= msk[getrt(a)];
                sz[getrt(b)] += sz[getrt(a)];
                par[getrt(a)] = getrt(b);
            }
        }
        long long cntx = 0, cnty = 0;
        for(int i = 1; i<=N; i++){
            if(par[i] == i){
                if(msk[i] == 1){
                    cntx += sz[i];
                }
                if(msk[i] == 2){
                    cnty += sz[i];
                }
            }
        }
        cout << cntx*cnty << "\n";
    }
}