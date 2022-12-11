#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    deque<int> dq;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        dq.push_back(n);
    }
    int A = 0, B = 0;
    for(int i = 1; i<=N; i++){
        int v = 0;
        if(dq.front() > dq.back()){
            v = dq.front();
            dq.pop_front();
        }
        else{
            v = dq.back();
            dq.pop_back();
        }
        if(i%2){
            A += v;
        }
        else{
            B += v;
        }
    }
    cout << A << " " << B << endl;
}