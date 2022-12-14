#include <bits/stdc++.h>

using namespace std;

string a[100];
string ans[100];
string s[100];

int main() {
	ios_base::sync_with_stdio(false);
    int n, k, q = 0, inx;
    for (int i = 0; i < 60; i++){
        s[i] = ((i / 26) + 'A');
        s[i] += ((i % 26) + 'a');
    }
    bool IsAllNo = true;
    cin >> n >> k;
    for (int i = 0; i <= n - k; i++)
        cin >> a[i];
    for (int i = 0; i <= n - k; i++){
        if (a[i] == "YES"){
            for (int j = i; j < k + i; j++)
                ans[j] = s[q ++];
            IsAllNo = false;
            inx = ++i;
            break;
        }
    }
    if (IsAllNo){
        for (int i = 0; i < n; i++)
            cout << "Abolfazl ";
        return 0;
    }
    for (int i = inx; i <= n - k; i++){
        if (a[i] == "NO")
            ans[i + k - 1] = ans[i];
        else
            ans[i + k - 1] = s[q ++];
    }
    for (int i = inx - 1; i >= 0; i--){
        if (a[i] == "NO")
            ans[i] = ans[i + k - 1];
        else
            ans[i] = s[q ++];
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}