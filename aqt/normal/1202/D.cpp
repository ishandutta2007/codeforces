#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> v;
        while(n>0){
            int l = 1, r = 1<<15, idx = 0;
            while(l <= r){
                int mid = l+r>>1;
                if(mid*(mid-1) <= 2*n){
                    idx = mid ;
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            v.push_back(idx);
            n -= idx*(idx-1)/2;
        }
        sort(v.begin(), v.end());
        cout << 1;
        int cnt = 0;
        for(int n : v){
            while(cnt < n){
                cnt++;
                cout << 3;
            }
            cout << 7;
        }
        cout << "\n";
    }
}