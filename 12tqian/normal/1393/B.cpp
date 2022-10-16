#include<bits/stdc++.h>
using namespace std;
void solve_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<int, int> cnt;
    for(int i = 0; i < n; i++) cnt[a[i]]++;
    int sum1 = 0;
    int sum2 = 0;
    for(auto x: cnt){
        if(2 <= x.second && x.second < 4) sum1 += x.second / 2 * 2;
        else if(x.second >= 4) sum2 += x.second / 2 * 2;
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        char c; int x; cin >> c >> x;
        if(cnt.find(x) == cnt.end()) cnt[x] = 0;
        if(2 <= cnt[x] && cnt[x] < 4) sum1 -= cnt[x]/2*2;
        else if(cnt[x] >= 4) sum2 -= cnt[x]/2*2;
        if(c == '+') cnt[x]++;
        else cnt[x]--;
        if(2 <= cnt[x] && cnt[x] < 4) sum1 += cnt[x] / 2 * 2;
        else if(cnt[x] >= 4) sum2 += cnt[x] / 2 * 2;
        if(sum2 >= 4 && sum1 + sum2 >= 8) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int test_cases = 1;
//    cin >> test_cases;
    while(test_cases--) solve_case();
    return 0;
}