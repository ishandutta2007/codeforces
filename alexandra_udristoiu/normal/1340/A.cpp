#include<iostream>
#include<set>
#define f first
#define s second
#define DIM 100005
using namespace std;
int n, i, x, t, ok;
int p[DIM], prv[DIM], nxt[DIM], val[DIM];
set< pair<int, int> > h;
set< pair<int, int> > :: iterator it;
int main(){
    cin>> t;
    for(; t; t--){
        cin>> n;
        for(i = 1; i <= n; i++){
            cin>> x;
            p[x] = i;
        }
        ok = 1;
        for(i = 1; i <= n; i++){
            val[i] = 1;
            h.insert( make_pair(-1, i) );
            prv[i] = i - 1;
            nxt[i] = i + 1;
        }
        for(i = 1; i <= n; i++){
            it = h.begin();
            if(val[ p[i] ] != - it->f){
                ok = 0;
            }
            x = p[i];
            nxt[ prv[x] ] = nxt[x];
            prv[ nxt[x] ] = prv[x];
            h.erase( make_pair(-val[x], x) );
            if(nxt[x] != n + 1){
                h.erase( make_pair( -val[ nxt[x] ], nxt[x]) );
                val[ nxt[x] ] = nxt[x] - prv[x];
                h.insert( make_pair(-val[ nxt[x] ], nxt[x]) );
            }
            val[x] = 0;
        }
        if(ok == 1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}