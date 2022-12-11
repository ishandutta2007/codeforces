#include <bits/stdc++.h>

using namespace std;

int rel[100005];
int who[100005];
int clr[100005];
int lst[100005];
vector<int> ans[5];

string query(vector<int> v){
    if(v.empty()){
        return "";
    }
    cout << "Q " << v.size()/2 << " ";
    for(int n : v){
        cout << n << " ";
    }
    cout << endl;
    string s;
    cin >> s;
    return s;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> v;
        for(int a = 1; a<=2; a++){
            for(int i = a; i+1<=N; i+=2){
                v.push_back(i);
                v.push_back(i+1);
            }
            string s = query(v);
            for(int i = 0; i<v.size(); i+=2){
                rel[v[i+1]] = s[i/2]-'0';
            }
            v.clear();
        }
        vector<int> cmp;
        cmp.push_back(1);
        who[1] = 1;
        for(int i = 2; i<=N; i++){
            if(rel[i]){
                who[i] = who[i-1];
            }
            else{
                who[i] = i;
                cmp.push_back(i);
            }
        }
        string s = query(v);
        for(int r = 0; r<4; r++){
            for(int i = r; i+2<cmp.size(); i+=4){
                v.push_back(cmp[i]);
                v.push_back(cmp[i+2]);
            }
            string s = query(v);
            for(int i = 0; i<v.size(); i+=2){
                lst[v[i+1]] = s[i/2] - '0';
            }
            v.clear();
        }
        clr[cmp[0]] = 1;
        if(cmp.size() >= 2){
            clr[cmp[1]] = 2;
        }
        for(int i = 2; i<cmp.size(); i++){
            if(lst[cmp[i]] == 1){
                clr[cmp[i]] = clr[cmp[i-2]];
            }
            else{
                clr[cmp[i]] = clr[cmp[i-1]]^clr[cmp[i-2]]^7;
            }
        }
        for(int k = 1; k<=4; k*=2){
            for(int i = 1; i<=N; i++){
                if(clr[who[i]] == k){
                    ans[k].push_back(i);
                }
            }
        }
        cout << "A " << ans[1].size() << " " << ans[2].size() << " " << ans[4].size() << endl;
        for(int k = 1; k<=4; k*=2){
            for(int n : ans[k]){
                cout << n << " ";
            }
            cout << endl;
            ans[k].clear();
        }
    }
}