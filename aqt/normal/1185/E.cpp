#include <bits/stdc++.h>

using namespace std;

int N, M;
int minix[50], maxix[50], miniy[50], maxiy[50];
char arr[2005][2005];
int T;
string s;
char c;

bool chk(){
    if(c=='.'){
        return true;
    }
    for(char t = c; t>='a'; t--){
        if(maxix[t-'a'] == 0){
            minix[t-'a'] = minix[t-'a'+1];
            maxix[t-'a'] = maxix[t-'a'+1];
            miniy[t-'a'] = miniy[t-'a'+1];
            maxiy[t-'a'] = maxiy[t-'a'+1];
        }
        if(minix[t-'a'] != maxix[t-'a'] && miniy[t-'a'] != maxiy[t-'a']){
            return false;
        }
        if(miniy[t-'a'] != maxiy[t-'a']){
            int x = minix[t-'a'];
            for(int j = miniy[t-'a']; j<=maxiy[t-'a']; j++){
                if(arr[x][j] < t){
                    return false;
                }
            }
        }
        else{
            int y = miniy[t-'a'];
            for(int i = minix[t-'a']; i<=maxix[t-'a']; i++){
                if(arr[i][y] < t){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M;
        fill(minix, minix+27, N+1);
        fill(maxix, maxix+27, 0);
        fill(miniy, miniy+27, M+1);
        fill(maxiy, maxiy+27, 0);
        c = '.';
        for(int i= 1; i<=N; i++){
            cin >> s;
            for(int j = 1; j<=M; j++){
                arr[i][j] = s[j-1];
                if(arr[i][j] != '.'){
                    c = max(c, arr[i][j]);
                    minix[s[j-1]-'a'] = min(minix[s[j-1]-'a'], i);
                    maxix[s[j-1]-'a'] = max(minix[s[j-1]-'a'], i);
                    miniy[s[j-1]-'a'] = min(miniy[s[j-1]-'a'], j);
                    maxiy[s[j-1]-'a'] = max(maxiy[s[j-1]-'a'], j);
                }
            }
        }
        if(chk()){
            cout << "YES" << "\n";
            if(c == '.'){
                cout << 0 << "\n";
                continue;
            }
            else{
                cout << c-'a'+1 << "\n";
            }
            for(char t = 'a'; t<=c; t++){
                cout << minix[t-'a'] << " " << miniy[t-'a'] << " " <<
                maxix[t-'a'] << " " << maxiy[t-'a'] << "\n";
            }
        }
        else{
            cout << "NO" << "\n";
        }
    }
}