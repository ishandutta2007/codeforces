#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    long long N = s.size();
    long long ans = N*(N+1)/2;
    for(int r = 1; r<=N; r++){
        for(int l = r, c = 8; l>0 && c>0; l--, c--){
            bool pos = 0;
            for(int k = l; k<=r; k++){
                for(int t = 1; t<=8; t++){
                    if(k+2*t <= r){
                        if(s[k-1] == s[k-1+t] && s[k-1] == s[k-1+2*t]){
                            pos = 1;
                        }
                    }
                }
            }
            if(!pos){
                ans--;
            }
        }
    }
    cout << ans << endl;
}