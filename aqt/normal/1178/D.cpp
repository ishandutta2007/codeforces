#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
deque<int> qu;

bool isprime(int n){
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int M = 0;
    if(N <= 2){
        cout << -1 << endl;
        return 0;
    }
    else if(N == 7){
        v.push_back({1, 2});
        v.push_back({1, 7});
        v.push_back({2, 3});
        v.push_back({3, 4});
        v.push_back({4, 5});
        v.push_back({5, 6});
        v.push_back({6, 7});
        M = 7;
    }
    else{
    for(int i = 1; i<=N-2; i+=3){
        v.push_back({i, i+1});
        v.push_back({i+1, i+2});
        v.push_back({i, i+2});
        qu.push_back(i), qu.push_back(i+1), qu.push_back(i+2);
        M+=3;
    }
    for(int i = N; i%3; i--){
        int f = qu.front();
        qu.pop_front();
        int s = qu.back();
        qu.pop_back();
        v.push_back({i, f});
        v.push_back({i, s});
        M += 2;
        qu.push_back(i);
    }
    while(!isprime(M)){
        int f = qu.front();
        qu.pop_front();
        int s = qu.back();
        qu.pop_back();
        M++;
        v.push_back({f, s});
    }
    }
    cout << M << "\n";
    for(auto p : v){
        cout << p.first << " " << p.second << "\n";
    }
}