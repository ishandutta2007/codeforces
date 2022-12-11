#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    set<int> st;
    deque<int> qu;
    for(int n = 1; n<=N; n++){
        int k;
        cin >> k;
        if(st.count(k)){
            continue;
        }
        else{
            st.insert(k);
            qu.push_front(k);
            if(qu.size() > K){
                st.erase(qu.back());
                qu.pop_back();
            }
        }
    }
    cout << qu.size() << "\n";
    while(qu.size()){
        cout << qu.front() << " ";
        qu.pop_front();
    }
}