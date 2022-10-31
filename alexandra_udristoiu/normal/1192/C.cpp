#include<iostream>
#include<cstring>
#include<map>
#define mod 998244353
using namespace std;
int n, i, m, j, x, y, z, t, sol, nr;
char s[15];
string c;
int a[12][70][70], d[70][70][70];
map<string, int> mp;
int getlet(char c){
    if(c >= 'a' && c <= 'z'){
        return c - 'a';
    }
    if(c >= 'A' && c <= 'Z'){
        return 26 + c - 'A';
    }
    return 52 + c - '0';
}
int dif(int x, int y, int z, int t){
    if(x != y && y != z && z != t){
        return 24;
    }
    if(x == y && y == z && z == t){
        return 1;
    }
    if(x == y && z == t){
        return 6;
    }
    if(x == y && y == z){
        return 4;
    }
    if(y == z && z == t){
        return 4;
    }
    return 12;
}
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> s;
        m = strlen(s);
        x = getlet(s[0]);
        y = getlet(s[m - 1]);
        c = s;
        if(mp[c] == 0){
            mp[c] = 1;
            a[m][x][y]++;
        }
        for(j = 0; j < m / 2; j++){
            swap(s[j], s[m - j - 1]);
        }
        c = s;
        if(mp[c] == 0){
            mp[c] = 1;
            a[m][y][x]++;
        }
    }
    for(i = 3; i <= 10; i++){
        for(x = 0; x < 62; x++){
            for(y = x; y < 62; y++){
                for(z = y; z < 62; z++){
                    d[x][y][z] = 0;
                    for(t = 0; t < 62; t++){
                        d[x][y][z] = (d[x][y][z] + a[i][x][t] * 1LL * a[i][y][t] % mod * a[i][z][t]) % mod;
                    }
                }
            }
        }
        for(x = 0; x < 62; x++){
            for(y = x; y < 62; y++){
                for(z = y; z < 62; z++){
                    for(t = z; t < 62; t++){
                        nr = d[x][y][z] * 1LL * d[x][y][t] % mod * d[x][z][t] % mod * d[y][z][t] % mod;
                        nr = nr * 1LL * dif(x, y, z, t) % mod;
                        sol += nr;
                        if(sol >= mod){
                            sol -= mod;
                        }
                    }
                }
            }
        }
    }
    cout<< sol;
}