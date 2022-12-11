#include <bits/stdc++.h>

using namespace std;

int pre[100005][3];
string s;
int Q;

int main(){
    cin >> s >> Q;
    int N = s.size();
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<3; j++){
            pre[i][j] = pre[i-1][j];
        }
        if(s[i-1] == 'x'){
            pre[i][0]++;
        }
        else if(s[i-1] == 'y'){
            pre[i][1]++;
        }
        else{
            pre[i][2]++;
        }
    }
    while(Q--){
        int l, r;
        cin >> l >> r;
        int diff = 0;
        for(int j= 0; j<3; j++){
            diff = max(diff, abs(pre[r][j]-pre[l-1][j]-pre[r][(j+1)%3]+pre[l-1][(j+1)%3]));
        }
        if(r-l+1 < 3 || diff <= 1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}