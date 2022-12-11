#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
long long BIT[400010];
vector<int> cmp;
unordered_set<int> st;

int getidx(int n){
    return lower_bound(cmp.begin(), cmp.end(), n) - cmp.begin();
}

void upd(int p){
    p = getidx(p);
    for(int i = p; i<=400009; i+=i&-i){
        BIT[i]++;
    }
}

long long query(int p){
    p = getidx(p);
    long long s = 0;
    for(int i = p; i>0; i-=i&-i){
        s += BIT[i];
    }
    return s;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i<=N; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({-y, x});
        cmp.push_back(x);
        cmp.push_back(x-1);
    }
    cmp.push_back(0);
    cmp.push_back(INT_MAX);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    sort(v.begin(), v.end());
    long long ans = 0, cnt = 0;
    for(int i = 0; i<v.size(); ){
        int lst = 0;
        int y = v[i].first;
        long long m = 0;
        while(i < v.size() && v[i].first == y){
            if(!st.count(v[i].second)){
                st.insert(v[i].second);
                cnt++;
                upd(v[i].second);
            }
            long long s = query(v[i].second-1) - query(lst);
            m += s*(s+1)/2;
            lst = v[i].second;
            i++;
        }
        long long s = query(INT_MAX)- query(lst);
        m += s*(s+1)/2;
        ans += cnt*(cnt+1)/2 - m;
    }
    cout << ans << endl;
}

/*

5
3 6
5 5
7 4
9 3
3 2

*/