#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
string s[555];
int a[555][555];
int sum[555];
int G[555];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = 0 ;j < n; j++)
            a[i][j] = s[i] == s[j];
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + (int)s[i-1].size();
    }
    int ans = sum[n] + n-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            G[j] = 1;
        for(int k = 0; k < n; k++){
            for(int j = i; j < n; j++){
                if(j + k >= n) break;
                if(!a[i+k][j+k]) G[j] = 0;
            }
            int cnt = 0;
            int j = i;
            while(j + k < n){
                if(G[j]){
                    ++cnt;
                    j += k + 1;
                }
                else {
                    j++;
                }
            }
            if(cnt >= 2){
                int len = sum[i + k + 1] - sum[i];
                ans = min(ans, sum[n] - cnt * len+ cnt * (k + 1) + (n-cnt*k) - 1);
            }
        }
    }
    cout << ans << "\n";
	return 0;
}