#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    while((int)s1.size() > (n + 1) / 2) {
        s1.pop_back();
    }
    reverse(s2.begin(), s2.end());
    while((int)s2.size() > n / 2) {
        s2.pop_back();
    }
    reverse(s2.begin(), s2.end());
    int x0 = 0, y0 = (int)s1.size() - 1;
    int x1 = 0, y1 = (int)s2.size() - 1;
    string ans;
    for(int i = 0; i < n; i++) {
        ans.push_back('?');
    }
    int x2 = 0, y2 = n - 1;
    for(int i = 0; i < (n - 1) / 2; i++) {
        if(s1[x0] < s2[y1]) {
            ans[x2] = s1[x0];
            x0++;
            x2++;
        } else {
            ans[y2] = s1[y0];
            y0--;
            y2--;
        }
 
        if(s2[y1] > s1[x0]) {
            ans[x2] = s2[y1];
            y1--;
            x2++;
        } else {
            ans[y2] = s2[x1];
            x1++;
            y2--;
        }
    }
    if(n % 2) {
        ans[x2] = s1[x0];
    } else {
        ans[x2] = s1[x0];
        ans[y2] = s2[x1];
        if(ans[x2] > ans[y2]) {
            swap(ans[x2], ans[y2]);
        }
    }
    cout << ans;
}