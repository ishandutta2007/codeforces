#include <bits/stdc++.h>

using namespace std;

int N, B = 225, S, X;
vector<pair<int, int>> v;
mt19937 g1(time_t(0));
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}

pair<int, int> query(int idx){
    pair<int, int> p;
    cout << "? " << idx << endl;
    cin >> p.first >> p.second;
    return p;
}

void ans(int idx){
    cout << "! " << idx << endl;
    exit(0);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S >> X;
    if(N < 2000){
        for(int i =1 ; i<=N; i++){
            v.push_back(query(i));
        }
        sort(v.begin(), v.end());
        if(lower_bound(v.begin(), v.end(), make_pair(X, -1)) == v.end()){
            ans(-1);
        }
        ans((*lower_bound(v.begin(), v.end(), make_pair(X, -1))).first);
    }
    else{
        v.push_back(query(S));
        if(v[0].first >= X){
            ans(v[0].first);
        }
        for(int i = 1; i<B; i++){
            int n = (rand()%N + rand()%N)%N + 1;
            v.push_back(query(n));
        }
        sort(v.begin(), v.end());
        int idx = (*(--lower_bound(v.begin(), v.end(), make_pair(X, -1)))).second;
        while(idx != -1){
            pair<int, int> p = query(idx);
            if(p.first == -1 && p.second == -1){
                exit(0);
            }
            if(p.first >= X){
                ans(p.first);
            }
            idx = p.second;
        }
        ans(-1);
    }
}