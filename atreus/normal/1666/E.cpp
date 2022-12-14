#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 77;
int len , n , a[N] , fr , fl;
pair < int , int > dp[N];
bool check(int le , int ri , bool pr = false) {
    int bl = 0 , br = 0;
    for(int i = 1;i <= n;++ i) {
        if(br + ri < a[i]) return false;
        bl += le;
        bl = max(bl , a[i]);
        br += ri;
        br = min(br , a[i + 1]);
        if(br < bl) return false;
        if(pr)
            dp[i] = make_pair(bl , br);
    }
    if(pr) {
        //cout << dp[1].first << ' ' << dp[1].second << endl;
        int last = len;
        vector < int > ans;
        for(int i = n - 1;i > 0;-- i) {
            if(last - dp[i].first <= ri) {
                ans.push_back(last - dp[i].first);
                last = dp[i].first;
            } else {
                ans.push_back(ri);
                last -= ri;
            }
        }
        ans.push_back(last);
        reverse(ans.begin() , ans.end());
        int f = 0;
        for(int x : ans) {
            printf("%d %d\n" , f , f + x);
            f += x;
        }

    }


    return (bl <= len && br >= len);
}
int main() {
    scanf("%d %d" , & len , & n);
    for(int i = 1;i <= n;++ i) scanf("%d" , a + i);
    a[n + 1] = len;
    int ll = 0 , rr = len;
    while(rr - ll > 1) {
        int md = ((ll + rr) / 2);
        if(check(0 , md))
            rr = md;
        else
            ll = md;
    }
    fr = rr;
    ll = 0 , rr = len;
    while(rr - ll > 1) {
        int md = ((ll + rr) / 2);
        if(check(md , len))
            ll = md;
        else
            rr = md;
    }
    fl = ll;
    check(fl , fr , true);
    //printf("%d %d" , fl , fr);
    return 0;
}