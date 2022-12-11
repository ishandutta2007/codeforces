#include <bits/stdc++.h>

using namespace std;

int N;
long long K;

deque<int> dq;

int main(){
    cin >> N >> K;
    K = N < K ? N : K;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        dq.push_back(n);
    }
    int s = dq.front();
    dq.push_back(dq.front());
    dq.pop_front();
    int cnt = 0;
    while(cnt < K){
        if(s <= dq.front()){
            cnt = 1;
            s = dq.front();
        }
        else{
            cnt++;
        }
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << s << endl;
}