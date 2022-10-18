#include <bits/stdc++.h>

using namespace std;

int a[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i, j, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    string out = "";
    i = 1, j = n;
    int last = -1;
    while (i <= j && a[i] != a[j]){
        if (a[i] <= a[j] && a[i] > last){
            last = a[i];
            i++;
            ans++;
            out += "L";
        }
        else if (a[j] <= a[i] && a[j] > last){
            last = a[j];
            j--;
            out += "R";
            ans++;
        }
        else{
            if (max(a[i], a[j]) > last){
                last = max(a[i], a[j]);
                if (a[i] > a[j]) ++i, out += "L";
                else --j, out += "R";
                ans++;
            }
            else break;
        }
    }
    if (i > j || max(a[i], a[j]) <= last){
        cout << ans << '\n';
        cout << out << '\n';
        return 0;
    }
    if (i == j){
        out += "L", ans++;
        cout << ans << '\n';
        cout << out << '\n';
        return 0;
    }
    int ans1 = 0, ans2 = 0;
    string out1 = "", out2 = "";
    int last1 = last;
    while (a[i] > last){
        ans1++;
        last = a[i];
        out1 += "L";
        ++i;
    }
    last = last1;
    while (a[j] > last){
        ans2++;
        last = a[j];
        out2 += "R";
        --j;
    }
    cout << ans + max(ans1, ans2) << '\n';
    if (ans1 >= ans2) cout << out + out1 << '\n';
    else cout << out + out2 << '\n';
    return 0;
}