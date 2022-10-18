#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int arr[1005], frm[1005];
vector<int> ans[1005];

void print(vector<int> &v) {
    int flag = 0;
    for (int i : v) {
        if (!flag)
            flag = 1;
        else
            cout << ".";
        cout << i; 
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stk;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
            if (arr[i] == 1)
                frm[i] = i - 1;
            else {
                while (!stk.empty() && arr[stk.back()] != arr[i] - 1)
                    stk.pop_back();
                assert(!stk.empty());
                frm[i] = stk.back(), stk.pop_back(); 
            }
            stk.pb(i);
        }
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[frm[i]];
            if (arr[i] == 1)
                ans[i].pb(1);
            else
                ++ans[i].back();
            print(ans[i]);
        }
    }
}