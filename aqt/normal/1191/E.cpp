#include <bits/stdc++.h>

using namespace std;

int N, K;
string s;
vector<int> v[2];

bool chk(){
    for(int i = K-1; i<N; i++){
        int l = i-K+1, r = i;
        int idx1 = 0, idx2 = 0;
        for(int b = 0; b<2; b++){
            if(v[b][0] < l){
                idx1 = v[b][0];
            }
            else{
                idx1 = *upper_bound(v[b].begin(), v[b].end(), r);
            }
            if(v[b].back() > r){
                idx2 = v[b].back();
            }
            else{
                idx2 = *(--lower_bound(v[b].begin(), v[b].end(), l));
            }
            if(idx2 - idx1 + 1 > K){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> s;
    for(int i = 0; i<N; i++){
        v[s[i]-'0'].push_back(i);
    }
    if(v[0].empty() || v[1].empty() || v[0].back() - v[0][0] + 1 <= K || v[1].back() - v[1][0] + 1 <= K){
        cout << "tokitsukaze" << endl;
        return 0;
    }
    if(K >= (N+1)/2){
        if(chk()){
            cout << "once again" << endl;
        }
        else{
            cout << "quailty" << endl;
        }
    }
    else{
        cout << "once again" << endl;
    }
}