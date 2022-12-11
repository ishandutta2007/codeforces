#include <bits/stdc++.h>

using namespace std;

int N;
priority_queue<pair<int, int>> t[2];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu[2];
int val[100005];
vector<pair<pair<int, int>, int>> ans;
bool done[100005];
int clr[100005];
int par[100005];

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int c, n;
        cin >> c >> n;
        val[i] = n;
        qu[c].push({n, i});
        t[c].push({n, i});
        clr[i] = c;
        par[i] = i;
    }
    for(int i = 1; i<N; i++){
        assert(qu[0].size() || qu[1].size());
        for(int j = 0; j<2; j++){
            while(qu[j].size() && qu[j].top().first != val[qu[j].top().second]){
                int n = qu[j].top().second;
                pair<int, int> k = {val[qu[j].top().second], qu[j].top().second};
                qu[j].pop();
                if(!done[n]){
                    qu[j].push(k);
                }
            }
        }
        if(qu[1].size() && (qu[0].empty() || qu[1].top().first < qu[0].top().first)){
            auto p = qu[1].top();
            bool b = 0;
            while(t[0].size()){
                if(t[0].top().first != val[t[0].top().second] || done[t[0].top().second]){
                    int n = t[0].top().second;
                    pair<int, int> k = {val[t[0].top().second], t[0].top().second};
                    t[0].pop();
                    if(!done[n]){
                        t[0].push(k);
                    }
                    continue;
                }
                auto q = t[0].top();
                t[0].pop();
                ans.push_back({{p.second, q.second}, p.first});
                val[p.second] = 0;
                done[p.second] = 1;
                val[q.second] -= p.first;
                par[p.second] = q.second;
                assert(p.second >= 0);
                t[0].push({val[q.second], q.second});
                b = 1;
                break;
            }
            if(!b){
                while(true){
                    int n = rand()%N+1;
                    //cout << p.second << " " << getrt(p.second) << " " << n << " " << getrt(n) << endl;
                    if(getrt(n) != getrt(p.second) && clr[n] != clr[p.second]){
                        par[getrt(n)] = getrt(p.second);
                        ans.push_back({{p.second, n}, 0});
                        break;
                    }
                }
            }
            qu[1].pop();
        }
        else{
            auto p = qu[0].top();
            bool b = 0;
            while(t[1].size()){
                if(t[1].top().first != val[t[1].top().second] || done[t[1].top().second]){
                    int n = t[1].top().second;
                    pair<int, int> k = {val[t[1].top().second], t[1].top().second};
                    t[1].pop();
                    if(!done[n]){
                        t[1].push(k);
                    }
                    continue;
                }
                auto q = t[1].top();
                t[1].pop();
                ans.push_back({{p.second, q.second}, p.first});
                val[p.second] = 0;
                done[p.second] = 1;
                val[q.second] -= p.first;
                par[p.second] = q.second;
                assert(p.second >= 0);
                t[1].push({val[q.second], q.second});
                b = 1;
                break;
            }
            if(!b){
                while(true){
                    int n = rand()%N+1;
                    if(getrt(n) != getrt(p.second) && clr[n] != clr[p.second]){
                        par[getrt(n)] = getrt(p.second);
                        ans.push_back({{p.second, n}, 0});
                        break;
                    }
                }
            }
            qu[0].pop();
        }
    }
    if(ans.size() != N-1){
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i<=N; i++){
            if(!done[i]){
                if(clr[i]){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
        }
        cout << cnt1 << " " << cnt2 << endl;
    }
    assert(ans.size() == N-1);
    for(auto p : ans){
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
}