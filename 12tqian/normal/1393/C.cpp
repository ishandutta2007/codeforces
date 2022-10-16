#include<bits/stdc++.h>
using namespace std;
void solve_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<int, int> cnts;
    for(int i = 0; i < n; i++) cnts[a[i]]++;
    vector<int> v;
    for(auto x: cnts) v.push_back(x.second);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if(v.size() == 1){
        cout << 0 << '\n';
        return;
    }
    int mx = v[0];
    int cnt = 0;
    for(int x: v) cnt += (mx == x);
    cout << (n - mx - (cnt - 1)) / (mx - 1) << '\n';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    while(test_cases--) solve_case();
    return 0;
}