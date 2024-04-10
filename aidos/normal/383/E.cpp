#include <bits/stdc++.h>

using namespace std;
const int maxn = (int)2e5 + 100;
int n, m;
int a[maxn];
int ans[1<<24];
int ans2[1<<24];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            a[i] |= (1<<(s[j] - 'a'));
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int cur = a[i] | a[j];
            cur ^= (1<<24) - 1;
            ans[cur] += 1;
        }
        ans2[((1<<24)-1)^a[i]] += n;
    }
    for(int i = 0; i < 24; i++) {
        for(int mask = 0; mask < (1<<24); mask++) {
            if(!(mask & (1<<i))) {
                ans[mask] += ans[mask^(1<<i)];
                ans2[mask] += ans2[mask^(1<<i)];
            }
        }
    }
    int c = 0;
    for(int i = 0; i < (1<<24); i++) {
        c ^= n * n - 2 * ans2[i] + ans[i];
    }
    cout << c << "\n";
}