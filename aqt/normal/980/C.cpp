#include <bits/stdc++.h>

using namespace std;

int N, K;
int cmp[256];
vector<int> vec;

int main(){
    cin >> N >> K;
    fill(cmp, cmp+256, -1);
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        if(cmp[n] != -1){
            cout << cmp[n] << " ";
            continue;
        }
        int mini = n;
        int j = n;
        for(; j>=0 && vec.size() < K; j--){
            if(cmp[j] == -1){
                vec.push_back(j);
                mini = j;
            }
            else{
                break;
            }
        }
        if(vec.size() < K && j>=0){
            int crnt = j;
            for(; j>=0; j--){
                if(cmp[j] != cmp[crnt]){
                    break;
                }
            }
            if(n-j <= K){
                mini = cmp[crnt];
            }
        }
        for(int k : vec){
            cmp[k] = mini;
        }
        cout << mini << " ";
        vec.clear();
    }
}