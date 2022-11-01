#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    long long ppap = 0LL;
    for(int i=0;i<n;i++) ppap += v[i];
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        long long x,y;
        cin >> x >> y;
        auto it = lower_bound(v.begin(), v.end(), x);
        if(it == v.begin()){
            cout << max(0LL, y-ppap+v[0]) << "\n";
        }
        else if(it == v.end()){
            cout << (x-v[n-1]) + max(0LL, y-ppap+v[n-1]) << "\n";
        }
        else{
            int idx = it - v.begin();
            cout << min(max(0LL, y-ppap+v[idx]), (x-v[idx-1]) + max(0LL, y-ppap+v[idx-1])) << "\n";
        }
    }
}