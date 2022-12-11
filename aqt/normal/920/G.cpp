#include <bits/stdc++.h>

using namespace std;

int Q;
vector<int> f;

int pos(int n){
    int tot = 0;
    int k = f.size();
    for(int m = 0; m<1<<k; m++){
        int a = 1;
        for(int b = 0; b<k; b++){
            if((1<<b)&m){
                a *= f[b];
            }
        }
        if(__builtin_popcount(m)%2 == 0){
            tot += n/a;
        }
        else{
            tot -= n/a;
        }
    }
    return tot;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        f.clear();
        int x, n, k;
        cin >> x >> n >> k;
        int N = n;
        for(int i= 2; i<=sqrt(n); i++){
            if(n%i == 0){
                f.push_back(i);
                while(n%i == 0){
                    n/=i;
                }
            }
        }
        if(n > 1){
            f.push_back(n);
        }
        n = N;
        k += pos(x);
        int l = x, r = 1000000000, ans = x;
        while(l <= r){
            int mid = l+r>>1;
            if(pos(mid) >= k){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}