#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define cd complex<double>
#define p_q priority_queue
#define int long long
using namespace std;

signed main(){
	AquA;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int ans=1e18;
    for(int i=0;i<n;i++){
        int sum=0,nw=0;
        for(int j=i-1;j>=0;j--){
            int z=nw/a[j]+1;
            sum+=z;
            nw=a[j]*z;
        }
        nw=0;
        for(int j=i+1;j<n;j++){
            int z=nw/a[j]+1;
            sum+=z;
            nw=a[j]*z;
        }
        ans=min(ans,sum);
    }
    cout << ans << "\n";
	return 0;
}