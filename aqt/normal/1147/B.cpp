#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> arr[100005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(true){
            int d = a-b;
            if(d < 0){
                d += N;
            }
            arr[a].push_back(d);
        }
        if(true){
            int d = b-a;
            if(d < 0){
                d += N;
            }
            arr[b].push_back(d);
        }
    }
    for(int i = 0; i<N; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    for(int d = 1; d<N; d++){
        if(N%d){
            continue;
        }
        bool b = 1;
        for(int i = 0, j = d; i<N; i++, j = (j+1)%N){
            if(arr[i].size() != arr[j].size()){
                b = 0;
                break;
            }
            int s = arr[i].size();
            for(int k = 0; k<s; k++){
                if(arr[i][k] != arr[j][k]){
                    b = 0;
                    break;
                }
            }
        }
        if(b){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}