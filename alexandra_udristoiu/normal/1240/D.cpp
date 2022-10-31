#include<iostream>
#include<set>
#define DIM 300005
#define f first
#define s second
using namespace std;
int n, q, nr, i;
int nxt[DIM], ind[DIM], v[DIM];
long long d[DIM], sol;
set< pair<int, int> > s[DIM];
set< pair<int, int> > :: iterator it;
int main(){
    cin>> q;
    for(; q; q--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> v[i];
        }
        nr = 0;
        nxt[n] = nxt[n + 1] = -1;
        for(i = n - 1; i >= 1; i--){
            if(v[i + 1] == v[i]){
                nxt[i] = i + 2;
            }
            else{
                if(nxt[i + 1] == -1){
                    nxt[i] = -1;
                }
                else{
                    it = s[ ind[i + 1] ].lower_bound( make_pair(v[i], 0) );
                    if(it != s[ ind[i + 1] ].end() && it->f == v[i]){
                        nxt[i] = it->s + 1;
                    }
                    else{
                        nxt[i] = -1;
                    }
                }
            }
            if(nxt[i] != -1){
                if(nxt[ nxt[i] ] != -1){
                    ind[i] = ind[ nxt[i] ];
                }
                else{
                    ind[i] = ++nr;
                }
                it = s[ ind[i] ].lower_bound( make_pair(v[ nxt[i] ], 0) );
                if(it != s[ ind[i] ].end() && it->f == v[ nxt[i] ]){
                    s[ ind[i] ].erase(it);
                }
                if(nxt[i] <= n){
                    s[ ind[i] ].insert( make_pair(v[ nxt[i] ], nxt[i]) );
                }
            }
        }
        for(i = 1; i <= nr; i++){
            s[i].clear();
        }
        d[n] = d[n + 1] = sol = 0;
        for(i = n - 1; i >= 1; i--){
            if(nxt[i] == -1){
                d[i] = 0;
            }
            else{
                d[i] = 1 + d[ nxt[i] ];
                sol += d[i];
            }
        }
        cout<< sol <<"\n";
    }
}