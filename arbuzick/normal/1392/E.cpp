#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
int t[25][25];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int k = 0, i1 = 0, j1 = 0;
    while(i1 < n){
        int i2 = i1, j2 = j1, x = 0;
        while(i2 < n && j2 >= 0){
            if(x%2 == 0)
                t[i2][j2] = 0;
            else
                t[i2][j2] = 1LL << k;
            x++, i2++, j2--;
        }
        if(j1+1 < n)
            j1++;
        else
            i1++;
        k++;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            cout << t[i][j] << ' ';
        cout << endl;
    }
    int q;
    cin >> q;
    while(q--){
        int s;
        cin >> s;
        i1 = 0, j1 = 0;
        k = 1;
        while(i1 < n){
            cout << i1+1 << ' ' << j1+1 << endl;
            if(j1+1 == n || (i1+1 < n && t[i1+1][j1] == (s&(1LL << k))))
                i1++;
            else
                j1++;
            k++;
        }
    }
    return 0;
}