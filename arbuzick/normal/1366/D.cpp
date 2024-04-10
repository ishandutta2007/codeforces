#include <bits/stdc++.h>
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> d(10000001);
    for(int i = 2; i < d.size(); ++i){
        if(d[i] != 0)
            continue;
        d[i] = i;
        for(int j = i*2; j < d.size(); j += i)
            if(d[j] == 0)
                d[j] = i;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> d1(n), d2(n);
    for(int i = 0; i < n; ++i){
        int d11 = d[a[i]], d21 = -1;
        while(a[i] > 1){
            //cout << a[i] << ' ' << d11 << ' ' << d[a[i]] << '\n';
            if(d[a[i]] != d11)
                d21 = max(d21, 1)*d[a[i]];
            a[i] /= d[a[i]];
        }
        //cout << '\n';
        if(d21 == -1)
            d1[i] = d2[i] = -1;
        else
            d1[i] = d11, d2[i] = d21;
    }
    for(int i = 0; i < n; ++i)
        cout << d1[i] << ' ';
    cout << '\n';
    for(int i = 0; i < n; ++i)
        cout << d2[i] << ' ';
    return 0;
}