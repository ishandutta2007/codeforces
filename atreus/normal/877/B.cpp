#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 500;
int befa[maxn], befb[maxn], afta[maxn], aftb[maxn];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = s.size();
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    int ans = 1000000000;
    if (s[0] == 'a')
        befa[0] = 1;
    for (int i = 1; i < n; i++){
        if (s[i] == 'a')
            befa[i] = befa[i - 1] + 1;
        else
            befa[i] = befa[i - 1];
    }
    if (s[n - 1] == 'a')
        afta[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--){
        if (s[i] == 'a')
            afta[i] = afta[i + 1] + 1;
        else
            afta[i] = afta[i + 1];
    }
    if (s[0] == 'b')
        befb[0] = 1;
    for (int i = 1; i < n; i++){
        if (s[i] == 'b')
            befb[i] = befb[i - 1] + 1;
        else
            befb[i] = befb[i - 1];
    }
    if (s[n - 1] == 'b')
        aftb[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--){
        if (s[i] == 'b')
            aftb[i] = aftb[i + 1] + 1;
        else
            aftb[i] = aftb[i + 1];
    }
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            bool cur = false, bak = false, bok = false;
            if (s[i] == 'a' && i != j)
                cur = true;
            if (s[j] == 'b')
                bak = true;
            if (s[i] == 'b')
                bok = true;
            int k = aftb[j] - bak + befb[i] - bok + (befa[j] - befa[i] + cur);
            ans = min(k, ans);
        }
    }
    cout << n - ans << endl;
}