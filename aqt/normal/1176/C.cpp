#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[6];
int seq[6] = {4, 8, 15, 16, 23, 42};

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int ans = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        for(int j = 0; j<6; j++){
            if(n == seq[j]){
                n = j;
                break;
            }
        }
        int j = n;
        if(j == 0){
            cnt[j]++;
        }
        else if(cnt[j-1] == 0){
            ans++;
        }
        else{
            cnt[j-1]--;
            cnt[j]++;
        }
    }
    for(int j =0; j<5; j++){
        ans += (j+1)*cnt[j];
    }
    cout << ans << endl;
}