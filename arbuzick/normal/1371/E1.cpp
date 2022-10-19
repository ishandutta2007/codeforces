#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> ans;
    for(int x = a[0]; x <= 2000; ++x){
        int k = 1;
        queue<int> b;
        int x1 = x;
        for(int i = 0; i < n; ++i){
            if(a[i] <= x1)
                b.push(i);
            else{
                while(x1 < a[i]&&!b.empty()){
                    if(b.size()%p == 0)
                        k = 0;
                    b.pop();
                    x1++;
                }
                if(x1 < a[i])
                    k = 0;
                else
                    b.push(i);
            }
        }
        while(!b.empty()){
            if(b.size()%p == 0)
                k = 0;
            b.pop();
            x1++;
        }
        if(k == 0)
            continue;
        ans.pb(x);
    }
    cout << ans.size() << "\n";
    for(auto x: ans)
        cout << x << ' ';
    return 0;
}