#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD = 1685518853;
long long sd[2];
long long pows[2][1000005];
vector<pair<long long, long long>> v, w;
string s, t;

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long sub(long long a, long long b){
    a = add(a, -b);
    if(a < 0){
        a += MOD;
    }
    return a;
}

void buildhsh(int l, int r){
    for(int i = l; i<r; i++){
        v.push_back({add(s[i], mult(v.back().first, sd[0])), add(s[i], mult(v.back().second, sd[1]))});
    }
}

pair<long long, long long> gethsh(int l, int r, int t){
    if(t == 1){
        return {sub(v[r].first, mult(v[l-1].first, pows[0][r-l+1])),
                    sub(v[r].second, mult(v[l-1].second, pows[1][r-l+1]))};
    }
    else{
        return {sub(w[r].first, mult(w[l-1].first, pows[0][r-l+1])),
                    sub(w[r].second, mult(w[l-1].second, pows[1][r-l+1]))};
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    sd[0] = 241, sd[1] = 131;
    pows[0][0] = pows[1][0] = 1;
    for(int i = 1; i<=1000000; i++){
        pows[0][i] = mult(pows[0][i-1], sd[0]);
        pows[1][i] = mult(pows[1][i-1], sd[1]);
    }
    cin >> s;
    int S = s.size();
    cout << s;
    v.push_back({0, 0});
    buildhsh(0, S);
    N--;
    while(N--){
        cin >> s;
        swap(v, w);
        v.clear();
        v.push_back({0, 0});
        buildhsh(0, (int) (s.size()));
        swap(v, w);
        int C = s.size();
        int b = 0;
        for(int i = 1; i<=min(S, C); i++){
            if(gethsh(S-i+1, S, 1) == gethsh(1, i, 2)){
                b = i;
            }
        }
        for(int i = b; i<s.size(); i++){
            cout << s[i];
            S++;
        }
        buildhsh(b, (int) (s.size()));
    }
}