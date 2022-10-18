#include <bits/stdc++.h>

using namespace std;

int a[200005];
int b[200005];
int to1[200005];
int to2[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i){
        to1[a[i]] = 1;
        to1[b[i]] = 2;
        to2[a[i]] = i;
        to2[b[i]] = i;
    }
    int pos = -1;
    for (int i = 1; i <= n; ++i){
        if (b[i] == 1) pos = i;
    }
    bool fl = true;
    if (pos != -1){
        for (int i = pos; i <= n; ++i) if (b[i] != i - pos + 1) fl = false;
        if (fl){
            for (int i = n - pos + 2; i <= n; ++i){
                if (to1[i] == 1 || (to1[i] == 2 && to2[i] <= i - (n - pos + 2))) continue;
                fl = false;
            }
        }
        if (fl){
            cout << pos - 1 << '\n';
            return 0;
        }
    }
    int l = -1, r = 2 * n + 1;
    bool check = true, flag;
    while (r - l > 1){
        check = true;
        flag = false;
        int m = (r + l) / 2;
        int mid = m;
        deque < int > bb;
        unordered_set < int > aa;
        for (int i = 1; i <= n; ++i){
            if (a[i] != 0) aa.insert(a[i]);
            bb.push_back(b[i]);
        }
        while (m > n){
            if ((int)aa.size() == n){
                flag = true;
                m = 0;
                break;
            }
            int xx = bb[0];
            bb.pop_front();
            bb.push_back(0);
            if (xx != 0) aa.insert(xx);
            m--;
        }
        int k = n - m;
        for (int i = m + 1; i <= n; ++i){
            if (bb[i - 1] != i - m) check = false;
        }
        while (m != 0){
            if (aa.find(n - m + 1) == aa.end()){
                check = false;
                break;
            }
            int xx = bb[0];
            bb.pop_front();
            if (xx != 0) aa.insert(xx);
            aa.erase(n - m + 1);
            --m;
        }
        if (flag) check = true;
        if (check) r = mid;
        else l = mid;
    }
    cout << r << '\n';
    return 0;
}