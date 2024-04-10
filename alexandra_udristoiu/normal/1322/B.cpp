#include<iostream>
using namespace std;
int n, i, pt, ii, p, u, sol;
long long nr;
int ff[40000005], v[400005];
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
    }
    for(ii = 0; (1 << ii) < 20000000; ii++){
        pt = (1 << (ii + 1) ) - 1;
        for(i = 1; i <= n; i++){
            ff[ (v[i] & pt) ]++;
        }
        for(i = 1; i <= pt; i++){
            ff[i] += ff[i - 1];
        }
        for(i = 0; i <= pt; i++){
            nr = 0;
            p = max(i + 1, (1 << ii) - i);
            u = pt - i;
            if(p <= u){
                nr += ff[u] - ff[p - 1];
            }
            p = max(i + 1, (1 << (ii + 1) ) + (1 << ii) - i);
            u = min(pt, (1 << (ii + 2) ) - 1);
            if(p <= u){
                nr += ff[u] - ff[p - 1];
            }
            nr *= ff[i] - ff[i - 1];
            if( ( ( (2 * i) >> ii) & 1) == 1){
                nr += (ff[i] - ff[i - 1]) * 1LL * (ff[i] - ff[i - 1] - 1) / 2;
            }
            if(nr % 2 == 1){
                sol ^= (1 << ii);
            }
        }
        for(i = 0; i <= pt; i++){
            ff[i] = 0;
        }
    }
    cout<< sol;
}