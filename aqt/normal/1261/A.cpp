#include <bits/stdc++.h>

using namespace std;

int T;
char arr[2005];
int N, K;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> K;
        vector<pair<int, int>> ans;
        for(int i = 1; i<=N; i++){
            cin >> arr[i];
        }
        for(int i = 1; i<=2*(K-1); i++){
            if(i%2 == 1){
                for(int j = i; j<=N; j++){
                    if(arr[j] == '('){
                        reverse(arr+i, arr+1+j);
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
            else{
                for(int j = i; j<=N; j++){
                    if(arr[j] == ')'){
                        reverse(arr+i, arr+1+j);
                        ans.push_back({i, j});
                        break;
                    }
                }
            }
        }
        for(int i = 2*(K-1)+1; i<=2*(K-1)+(N-2*(K-1))/2; i++){
            for(int j = i; j<=N; j++){
                if(arr[j] == '('){
                    reverse(arr+i, arr+1+j);
                    ans.push_back({i, j});
                    break;
                }
            }
        }
        for(int i = 2*(K-1)+(N-2*(K-1))/2+1; i<=N; i++){
            for(int j = i; j<=N; j++){
                if(arr[j] == ')'){
                    reverse(arr+i, arr+1+j);
                    ans.push_back({i, j});
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto p : ans){
            cout << p.first << " " << p.second << "\n";
        }
    }
}