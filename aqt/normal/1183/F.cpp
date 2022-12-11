#include <bits/stdc++.h>

using namespace std;

int main(){
    int Q;
    cin >> Q;
    while(Q--){
        int N;
        cin >> N;
        vector<int> v;
        for(int i = 1; i<=N; i++){
            int n;
            cin >> n;
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        N = (int) v.size();
        int ans = 0;
        for(int i = 0; i<N; i++){
            ans = max(v[i], ans);
            for(int j= i-1; j>=0; j--){
                if(v[i]%v[j] != 0){
                    ans = max(v[i] + v[j], ans);
                    for(int k = j-1; k>=0; k--){
                        if(v[i]%v[k] != 0 && v[j]%v[k] != 0){
                            ans = max(v[i] + v[j] + v[k], ans);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}