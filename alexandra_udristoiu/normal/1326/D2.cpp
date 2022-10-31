#include<iostream>
#include<cstring>
#define DIM 1000005
using namespace std;
int t, n, i, maxim, p, poz, ii, m, x, y, val;
char v[DIM], s[2 * DIM];
int d[2 * DIM];
int main(){
    cin>> t;
    for(; t; t--){
        cin>> v + 1;
        n = strlen(v + 1);
        p = 0;
        while(p < n / 2 && v[p + 1] == v[n - p]){
            p++;
        }
        maxim = 2 * p;
        poz = p;
        for(i = 1; i <= n; i++){
            s[2 * i - 1] = v[i];
            s[2 * i] = '*';
        }
        m = 2 * n - 1;
        s[0] = '#';
        s[m + 1] = '?';
        ii = 0;
        for(i = 1; i <= m; i++){
            d[i] = 0;
            if(ii + d[ii] >= i){
                d[i] = min(ii + d[ii] - i, d[2 * ii - i]);
            }
            while(s[ i + d[i] + 1] == s[i - d[i] - 1]){
                d[i]++;
            }
            if(i + d[i] > ii + d[ii]){
                ii = i;
            }
        }
        for(i = 1; i <= m / 2 + 1; i++){
            if(i % 2 == 1){
                x = i / 2;
                y = x - d[i] / 2;
                if(x >= p && p >= y){
                    val = 2 * p + (x - p) * 2 + 1;
                    if(val > maxim){
                        maxim = val;
                        poz = maxim - p;
                    }
                }
            }
            else{
                x = i / 2;
                y = x - d[i] / 2 - d[i] % 2;
                if(x >= p && p >= y){
                    val = 2 * p + 2 * (x - p);
                    if(val > maxim){
                        maxim = val;
                        poz = maxim - p;
                    }
                }
            }
        }
        for(i = 1; i <= m / 2; i++){
            swap(d[i], d[m - i + 1]);
        }
        for(i = 1; i <= m / 2 + 1; i++){
            if(i % 2 == 1){
                x = i / 2;
                y = x - d[i] / 2;
                if(x >= p && p >= y){
                    val = 2 * p + (x - p) * 2 + 1;
                    if(val > maxim){
                        maxim = val;
                        poz = p;
                    }
                }
            }
            else{
                x = i / 2;
                y = x - d[i] / 2 - d[i] % 2;
                if(x >= p && p >= y){
                    val = 2 * p + 2 * (x - p);
                    if(val > maxim){
                        maxim = val;
                        poz = p;
                    }
                }
            }
        }
        for(i = 1; i <= poz; i++){
            cout<< v[i];
        }
        maxim -= poz;
        for(i = n - maxim + 1; i <= n; i++){
            cout<< v[i];
        }
        cout<<"\n";
    }
}