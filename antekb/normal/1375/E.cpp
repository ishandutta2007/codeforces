#include<bits/stdc++.h>
using namespace std;
vector<int> V;
int main(){
    int n;
    cin>>n;
    V.resize(n);
    for(int i=0; i<n; i++){
        cin>>V[i];
    }
    vector<pair<int, int> > ans;
    for(int i=0; i<n; i++){
        ans.push_back({V[i], i});
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<n; i++){
        V[ans[i].second]=i;
    }
    ans.clear();
    for(int i=0; i<n; i++){
        /*for(int j=0; j<n; j++){
            cout<<V[j]<<" ";
        }
        cout<<"\n";*/
        vector<int> V2;
        for(int j=i+1; j<n; j++){
            if(V[j]<V[i])V2.push_back(j);
        }
        //cout<<V2.size()<<" "<<"a\n";
        sort(V2.begin(), V2.end(), [](int a, int b){return V[a]>V[b];});
        for(int j=0; j<V2.size(); j++){
            ans.push_back(make_pair(i, V2[j]));
            swap(V[i], V[V2[j]]);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<i.first+1<<" "<<i.second+1<<"\n";
    }
}