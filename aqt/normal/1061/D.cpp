#include <bits/stdc++.h>

using namespace std;

int N;
long long M, B;
int l[100005], r[100005];
priority_queue<int> pq;
vector<pair<int, int>> v;
long long MOD = 1e9+7;

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> B >> M;
    for(int i = 1; i<=N; i++){
        cin >> l[i] >> r[i];
        v.push_back({l[i], -i});
        v.push_back({r[i], i});
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for(auto p : v){
        if(p.second < 0){
            p.second *= -1;
            if(pq.empty() || M*(p.first - pq.top()) > B){
                ans = add(ans, add(B, M*r[p.second]-M*l[p.second]));
            }
            else{
                ans = add(ans, M*r[p.second]-M*pq.top());
            }
            if(pq.size()){
                pq.pop();
            }
        }
        else{
            pq.push(p.first);
        }
    }
    cout << ans << endl;
}