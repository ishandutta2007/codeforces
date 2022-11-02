#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
     cin>>n>>m;
    long long int dist[n];
    int from[n];
    for(int i = 0 ; i<n ; i++){
        dist[i] = 1ll<<50;
        from[i] = -1;
    }

    vector<vector<pair<int,int>>> g(n);
    set<pair<long long,int>> q;
    for(int i = 0 ; i<m ; i++){
        int u,v,d;
        cin>>u>>v>>d;
        g[u-1].push_back(make_pair(v,d));
        g[v-1].push_back(make_pair(u,d));
    }
    dist[0] = 0;
    from[0] = 1;
    pair<int,int> vov = make_pair(0,1);
    q.insert(vov);
    while(!q.empty()){
        pair<long long,int> p = *q.begin();
        q.erase(p);
        //cout<<"popped  v: "<<p.second<<" dist: "<<p.first<<endl;
    /*if(dist[p.second-1] < p.first){
            //cout<<"continuing"<<endl;
            continue;
        }*/
        //cout<<"31"<<endl;
        int u = p.second;
        dist[u-1] = p.first;
        //cout<<"34"<<endl;
        //from[u-1] =
        for(int i = 0 ; i<g[u-1].size() ; i++){
            //cout<<"comparing: "<<dist[g[u-1][i].first-1]<<"  and: "<<p.first + g[u-1][i].second<<endl;
            if(dist[g[u-1][i].first-1] > p.first + g[u-1][i].second){
                pair<long long,int> vo = make_pair(p.first + g[u-1][i].second,g[u-1][i].first);
                q.insert(vo);
                pair<long long,int> re= make_pair(dist[g[u-1][i].first-1],g[u-1][i].first);
                q.erase(re);
                dist[g[u-1][i].first-1] = p.first + g[u-1][i].second;
                from[g[u-1][i].first-1] = u;
                //cout<<"pushed  v: "<<g[u-1][i].first<<" dist: "<<p.first + g[u-1][i].second<<"  from: "<<u<<endl;
            }
        }
    }
    //for(int i = 0; i <n ; i++){
    /*if(dist[i] == INT_MAX) cout<<-1;
        else cout<<dist[i]<<endl;}*/
    //cout<<endl;
    //cout<<endl;
    int i = n-1;
    //for(int j = 0 ; j<n ; j++) cout<<from[j]<<" ";
    //cout<<endl;
    if(from[i] == -1) cout<<-1<<endl;
        else{
            vector<int > s;
            s.push_back(n);
            //for(int j = 0 ;j<s.size() ; j++) cout<< s[j]<<" ";
            //cout<<endl;
            //cout<<"while"<<endl;
            while(i>0){
                //cout<<from[i]<<" "<<endl;
                 s.push_back(from[i]);
                i = from[i]-1;

                //for(int j = 0 ;j<s.size() ; j++) cout<< s[j]<<" ";
                //cout<<endl;
            }
            //cout<<endl;
            //cout<<endl;
            //s.push_back(1);
            for(int j = s.size()-1 ; j>=0 ; j--){
                cout<<s[j]<<" ";
            }
        }
}