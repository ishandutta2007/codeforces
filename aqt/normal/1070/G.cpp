#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[105], brr[105];
vector<pair<int, pair<int, int>>> v;
vector<int> ans;

int main(){
    cin >> N >> M;
    for(int i = 1; i<=M; i++){
        pair<int, pair<int, int>> p;
        p.second.second = i;
        cin >> p.first >> p.second.first;
        v.push_back(p);
    }
    for(int n = 1; n<=N; n++){
        cin >> arr[n];
    }
    for(int n = 1; n<=N; n++){
        vector<pair<int ,pair<int, int>>> lft, rht;
        for(auto p : v){
            if(p.first <= n){
                lft.push_back(p);
            }
            else{
                rht.push_back(p);
            }
        }
        sort(lft.begin(), lft.end(), greater<pair<int, pair<int, int>>>());
        sort(rht.begin(), rht.end());
        if(true){
            ans.clear();
            for(int n = 1; n<=N; n++){
                brr[n] = arr[n];
            }
            bool e = 1;
            stack<int> stk;
            for(auto p : lft){
                bool w = 1;
                int hp = p.second.first;
                for(int i = p.first; i<=n; i++){
                    hp += brr[i];
                    if(hp < 0){
                        stk.push(p.second.second);
                        w = 0;
                        break;
                    }
                }
                if(w){
                    for(int i = p.first; i<=n; i++){
                        brr[i] = 0;
                    }
                    ans.push_back(p.second.second);
                    while(stk.size()){
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                }
            }
            if(stk.size()){
                e = 0;
            }
            for(auto p : rht){
                bool w = 1;
                int hp = p.second.first;
                for(int i = p.first; i>=n; i--){
                    hp += brr[i];
                    if(hp < 0){
                        stk.push(p.second.second);
                        w = 0;
                        break;
                    }
                }
                if(w){
                    for(int i = p.first; i>=n; i--){
                        brr[i] = 0;
                    }
                    ans.push_back(p.second.second);
                    while(stk.size()){
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                }
            }
            if(stk.size()){
                e = 0;
            }
            if(e){
                cout << n << endl;
                for(int k : ans){
                    cout << k << " ";
                }
                return 0;
            }
        }
        if(true){
            ans.clear();
            for(int n = 1; n<=N; n++){
                brr[n] = arr[n];
            }
            bool e = 1;
            stack<int> stk;
            for(auto p : rht){
                bool w = 1;
                int hp = p.second.first;
                for(int i = p.first; i>=n; i--){
                    hp += brr[i];
                    if(hp < 0){
                        stk.push(p.second.second);
                        w = 0;
                        break;
                    }
                }
                if(w){
                    for(int i = p.first; i>=n; i--){
                        brr[i] = 0;
                    }
                    ans.push_back(p.second.second);
                    while(stk.size()){
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                }
            }
            if(stk.size()){
                e = 0;
            }
            for(auto p : lft){
                bool w = 1;
                int hp = p.second.first;
                for(int i = p.first; i<=n; i++){
                    hp += brr[i];
                    if(hp < 0){
                        stk.push(p.second.second);
                        w = 0;
                        break;
                    }
                }
                if(w){
                    for(int i = p.first; i<=n; i++){
                        brr[i] = 0;
                    }
                    ans.push_back(p.second.second);
                    while(stk.size()){
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                }
            }
            if(stk.size()){
                e = 0;
            }
            if(e){
                cout << n << endl;
                for(int k : ans){
                    cout << k << " ";
                }
                return 0;
            }
        }
    }
    cout << -1 << endl;
}