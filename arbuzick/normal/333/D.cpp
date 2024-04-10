#include <bits/stdc++.h>
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define pb push_back
using namespace std;
int a[1000][1000];
signed main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    int ans = 0;
    for(int s1 = 0; s1 < n; ++s1){
        for(int s2 = s1+1; s2 < n; ++s2){
            int pr = min(a[s1][0], a[s2][0]);
            for(int j = 1; j < m; ++j){
                int k = min(a[s1][j], a[s2][j]);
                ans = max(ans, min(pr, k));
                if(k > pr)
                    pr = k;
            }
        }
    }
    cout << ans;
    return 0;
}