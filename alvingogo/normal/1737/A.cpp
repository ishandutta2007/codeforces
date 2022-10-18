#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26,0);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<min(26,n/k+1);j++){
                if(j==n/k){
                    cout << char(j+'a');
                    break;
                }
                if(cnt[j]>0){
                    cnt[j]--;
                }
                else{
                    cout << char(j+'a');
                    break;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}