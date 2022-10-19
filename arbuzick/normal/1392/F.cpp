#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    int s = 0;
    for(int i = 0; i < n; ++i)
        cin >> h[i], s += h[i];
    if((s-n*(n-1)/2)%n == 0){
        for(int i = 0; i < n; ++i)
            cout << (s-n*(n-1)/2)/n+i << ' ';
        return 0;
    }
    for(int i = 0; i < n-1; ++i){
        int s1 = (n-1)*(n-2)/2+i;
        if((s-s1)% n == 0){
            for(int j = 0; j <= i; ++j)
                cout << (s-s1)/n+j << ' ';
            for(int j = i+1; j < n; ++j)
                cout << (s-s1)/n+j-1 << ' ';
            return 0;
        }
    }
    return 0;
}