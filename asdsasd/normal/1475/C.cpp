#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    long long ans = ((long long)k * (long long)(k - 1)) / (long long)2;
    vector<int> cnt_a(a);
    vector<int> cnt_b(b);
    for(int i = 0; i < k; i++){
        scanf("%d", &a);
        a--;
        ans -= (long long)cnt_a[a];
        cnt_a[a]++;
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &b);
        b--;
        ans -= (long long)cnt_b[b];
        cnt_b[b]++;
    }
    cout << ans << endl;
}

int main(void){
    int t;
    scanf("%d", &t);
    while(t--) solve();
}