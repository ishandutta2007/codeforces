#include <bits/stdc++.h>

using namespace std;

int N;
bool gen[5005];
int cnt[500][2];

int main(){
    cin >> N;
    int ans = 0;
    for(int i = 1; i<=N; i++){
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'M'){
            for(int j = a; j<=b; j++){
                cnt[j][0]++;
                ans = max(ans, min(cnt[j][1], cnt[j][0]));
            }
        }
        else{
            for(int j = a; j<=b; j++){
                cnt[j][1]++;
                ans = max(ans, min(cnt[j][1], cnt[j][0]));
            }
        }
    }
    cout << 2*ans << endl;
}