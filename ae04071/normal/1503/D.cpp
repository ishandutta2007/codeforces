#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int n,dp[200001][2],c[200001][2];
pii a[200000];

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].first, &a[i].second);

    sort(a,a+n, [](const pii &a,const pii &b) {
            return min(a.first, a.second) < min(b.first, b.second);
            });


    for(int i=0;i<n;i++) if(min(a[i].first, a[i].second) > n) {
        puts("-1");
        return 0;
    }


    {
        int m[2] = {n*2+1, n*2+1};
        for(int i=0;i<n;i++) {
            int v = max(a[i].first, a[i].second);
            if(m[0] > v)
                m[0] = v;
            else if(m[1] > v)
                m[1] = v;
            else {
                puts("-1");
                return 0;
            }
        }
    }

    int nc=0, cc[2] = {0,}, m=2*n+1;
    int mm[2] = {n*2+1, n*2+1};
    for(int i=0;i<n;i++) {
        int v = max(a[i].first, a[i].second);
        m = min(m, v);

        if(mm[0] > v) {
            mm[0] = v;
            cc[(v == a[i].first)]++;
        }
        else if(mm[1] > v) {
            mm[1] = v;
            cc[(v == a[i].first) ^ 1]++;
        }
        
        if(m == 2*n - i) {
            nc++;
            c[nc][0] = cc[0];
            c[nc][1] = cc[1];
            m = 2*n + 1;
            cc[0] = cc[1] = 0;
        }
    }

    for(int i=1;i<=nc;i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + c[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + c[i][1];
    }

    printf("%d\n", min(dp[nc][0], dp[nc][1]));
    
    return 0;
}