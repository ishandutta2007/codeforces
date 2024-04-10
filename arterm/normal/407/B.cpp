#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 1020
#define mod 1000000007

int n, p[M], d[M];

void read(void){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> p[i];
        p[i]--;
    }
}

void din(void){
    for (int i = 0; i < n; ++i){
        int s = 2;
        for (int j = p[i]; j < i; ++j){
            s += d[j];
            if (s >= mod)
                s -= mod;
        }

        d[i] = s;
        //cout << i << "-" << d[i] << "\n";
    }

    int ans = 0;
    for (int i = 0; i < n; ++i){
        ans = ans + d[i];
        if (ans >= mod)
            ans -= mod;
    }

    cout << ans << "\n";
    
}

int main(){
#ifdef GORILLA
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    read();
    din();

    return 0;
}