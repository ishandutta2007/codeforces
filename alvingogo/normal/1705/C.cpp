#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c;
        cin >> c;
        int q;
        cin >> q;
        string s;
        cin >> s;
        long long nw=n;
        vector<long long> f(c),z(c);
        for(int i=0;i<c;i++){
            long long a,b;
            cin >> a >> b;
            a--;
            b--;
            f[i]=nw;
            z[i]=a;
            nw+=b-a+1;
        }
        for(int i=0;i<q;i++){
            long long k;
            cin >> k;
            k--;
            for(int j=c-1;j>=0;j--){
                if(f[j]>k){
                    continue;
                }
                k=k-f[j]+z[j];
            }
            cout << s[k] << "\n";
        }
    }
    return 0;
}