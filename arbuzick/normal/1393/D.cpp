#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int a[2000][2000];
int dp[2000][2000];
vector<int> st1, st2, q1, q2;
void push(int n) {
    q1.push_back(n);
    if (st1.empty())
        st1.push_back(n);
    else
        st1.push_back(min(n, st1.back()));
}
void pop() {
    if (q2.empty()) {
        while (!q1.empty()) {
            q2.push_back(q1.back());
            if (st2.empty())
                st2.push_back(q1.back());
            else
                st2.push_back(min(st2.back(), q1.back()));
            q1.pop_back();
            st1.pop_back();
        }
    }
    if (q2.empty()) {
        cout << -1 << "\n";
        return;
    }
    q2.pop_back();
    st2.pop_back();
}
int get(){
    if(st1.empty())
        return st2.back();
    if(st2.empty())
        return st1.back();
    return min(st1.back(), st2.back());
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    int i = n-1, j = 0;
    int i1 = n-1, j1 = 0;
    while(j < m){
        if(i+1 == n || j-1 == -1 || s[i+1][j-1] != s[i][j])
            a[i][j] = 1;
        else
            a[i][j] = 1+a[i+1][j-1];
        if(i+1 < n && j+1 < m)
            i++, j++;
        else{
            if(i1 != 0)
                i1--;
            else
                j1++;
            i = i1;
            j = j1;
        }
    }
    i = n-1, j = 0;
    while(j < m){
        int li = i, lj = j, ri = i, rj = j;
        st1.clear(), st2.clear(), q1.clear(), q2.clear();
        push(a[i][j]);
        dp[li][lj] = 1;
        while(li < n && lj < m){
            if(get() >= ri-li+2 && ri+1 < n && rj+1 < m && s[ri+1][rj+1] == s[ri][rj] && s[ri+1][rj] == s[ri][rj] && a[ri+1][rj+1] >= ri-li+2 && a[ri+1][rj]+1 >= ri-li+2){
                ri++, rj++;
                push(a[ri][rj-1]+1);
                push(a[ri][rj]);
                dp[li][lj]++;
            }else{
                pop();
                if(ri > li)
                    pop();
                li++, lj++;
                if(li < n && lj < m){
                    dp[li][lj] = 1;
                    if(s[li-1][lj-1] == s[li][lj])
                        dp[li][lj] = max(dp[li][lj], dp[li-1][lj-1]-1);
                }
                if(ri < li){
                    ri++, rj++;
                    if(ri < n && rj < m)
                        push(a[ri][rj]);
                }
            }
        }
        if(i != 0)
            i--;
        else
            j++;
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            ans += dp[i][j];
    cout << ans;
    return 0;
}