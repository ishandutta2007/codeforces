#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <map>
using namespace std;
int a[21][333111], n, m, z, x = 1, u = 0, t, p, b;
void f(){
    x = 1;
    for(int i = 0, u = 0; i<n; i++, u++){
        if(x) {
            if(p%2) {
                a[u+1][p/2] = (a[u][p-1]) | (a[u][p]);
            }
            else a[u+1][p/2] = (a[u][p]) | (a[u][p+1]);
        }
        else {
            if(p%2){
                a[u+1][p/2] = a[u][p-1] ^ a[u][p];
            }
            else {
                a[u+1][p/2] = a[u][p] ^ a[u][p+1];
            }
        }
        p/=2;
        x = 1-x;
    }
}
int main () {
    scanf("%d%d", &n, &m);
    t = z = 1<<n;
    for(int i = 0; i<z; i++){
        scanf("%d", &(a[0][i]));
    }                        
    while(z){
        if(x){
            for(int i = 0; i<z; i+=2){
                a[u+1][i/2] = a[u][i] | a[u][i+1];
            }
        }        
        else {
            for(int i = 0; i<z; i+=2){
                a[u+1][i/2] = a[u][i] ^ a[u][i+1];
            }
        }
        z/=2;
        u++;
        x = 1-x;
    }

    for(int i = 0; i<m; i++){
        scanf("%d%d", &p, &b);
        p--;
        a[0][p] = b;
        f();
        printf("%d\n", a[n][0]);
    }
	return 0;
}