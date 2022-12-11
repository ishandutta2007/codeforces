#include <bits/stdc++.h>

using namespace std;

int Q, N;
long long x, a, y, b, n;
long long t;
vector<long long> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    while(Q--){
        cin >> N;
        for(int i = 1; i<=N; i++){
            cin >> n;
            v.push_back(n/100);
        }
        cin >> x >> a >> y >> b >> t;
        if(x < y){
            swap(a, b);
            swap(x, y);
        }
        sort(v.begin(), v.end(), greater<long long>());
        int l = 1, r = N, ans = -1;
        while(l <= r){
            long long mid = l+r>>1;
            long long divab = (mid/(a*b/__gcd(a, b)));
            long long diva = mid/a-divab;
            long long divb = mid/b-divab;
            long long tot = 0;
            for(int i = 0; i<divab; i++){
                tot += 1LL*v[i]*(x+y);
            }
            for(int i = divab; i<divab+diva; i++){
                tot += 1LL*v[i]*x;
            }
            for(int i = divab+diva; i<diva+divab+divb; i++){
                tot += 1LL*v[i]*y;
            }
            if(tot < t){
                l = mid + 1;
            }
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        cout << ans << "\n";
        v.clear();
    }
}