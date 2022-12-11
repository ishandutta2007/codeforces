#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[3][100005];
unordered_set<int> st[100005];
vector<int> graph[100005];
set<pair<int, int>> ed;
queue<int> qu;
vector<int> ans;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i<=N-2; i++){
            cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
            st[arr[0][i]].insert(i);
            st[arr[1][i]].insert(i);
            st[arr[2][i]].insert(i);
            if(arr[0][i] > arr[1][i]){
                swap(arr[0][i], arr[1][i]);
            }
            if(arr[1][i] > arr[2][i]){
                swap(arr[1][i], arr[2][i]);
            }
            if(arr[0][i] > arr[1][i]){
                swap(arr[0][i], arr[1][i]);
            }
        }
        for(int i = 1; i<=N; i++){
            if(st[i].size() == 1){
                qu.push(i);
            }
            //cout << i << " " << qu.size() << endl;
        }
        for(int k = 1; k<=N-2; k++){
            int n = qu.front();
            qu.pop();
            int s = *st[n].begin();
            for(int i = 0; i<3; i++){
                st[arr[i][s]].erase(s);
                if(st[arr[i][s]].size() == 1){
                    qu.push(arr[i][s]);
                }
                for(int j = i+1; j<3; j++){
                    pair<int, int> p = {arr[i][s], arr[j][s]};
                    if(ed.count(p)){
                        ed.erase(p);
                    }
                    else{
                        ed.insert(p);
                    }
                }
            }
            ans.push_back(s);
        }
        for(auto p : ed){
            graph[p.first].push_back(p.second);
            graph[p.second].push_back(p.first);
        }
        int lst = 0, crnt = 1;
        do{
            cout << crnt << " ";
            for(int e : graph[crnt]){
                if(e != lst){
                    lst = crnt;
                    crnt = e;
                    break;
                }
            }
        }
        while(crnt != 1);
        cout << "\n";
        for(int n : ans){
            cout << n << " ";
        }
        cout << "\n";
        for(int i = 1; i<=N; i++){
            graph[i].clear();
            st[i].clear();
        }
        ed.clear();
        ans.clear();
        while(qu.size()){
            qu.pop();
        }
    }
}