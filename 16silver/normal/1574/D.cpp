#include <bits/stdc++.h>
using namespace std;
vector<array<int,10>> st;
vector<int> v[10];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        v[i].resize(k);
        for(int j=0;j<k;j++) cin >> v[i][j];
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        array<int,10> tmp;
        for(int j=0;j<10;j++) tmp[j]=0;
        for(int j=0;j<n;j++) cin >> tmp[j];
        st.push_back(tmp);
    }
    sort(st.begin(),st.end());
    priority_queue<pair<pair<int,int>,array<int,10>>> pq;
    array<int,10> hey;
    int hhey = 0;
    for(int i=0;i<10;i++) hey[i]=0;
    for(int i=0;i<n;i++) hey[i]=v[i].size(), hhey += v[i].back();
    pq.push({{hhey,0}, hey});
    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        auto it = lower_bound(st.begin(),st.end(),tmp.second);
        if(it == st.end() || *it != tmp.second){
            for(int i=0;i<n;i++) cout << tmp.second[i] << " ";
            return 0;
        }
        for(int i=tmp.first.second;i<n;i++){
            if(tmp.second[i] != 1){
                tmp.second[i]--;
                pq.push({{tmp.first.first - v[i][tmp.second[i]] + v[i][tmp.second[i]-1], i},tmp.second});
                tmp.second[i]++;
            }
        }
    }
}