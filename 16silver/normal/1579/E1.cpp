#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    deque<int> dq;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(dq.empty() || dq.front() > x) dq.push_front(x);
        else dq.push_back(x);
    }
    for(int i=0;i<n;i++) cout << dq[i] << " ";
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}