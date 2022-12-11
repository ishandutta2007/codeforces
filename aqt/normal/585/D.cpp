#include <bits/stdc++.h>

using namespace std;

int N;
int arr[30][3];
map<pair<int, int>, int> mpm;
map<pair<int, int>, int> mpv;
long long ansm = 0, ansv = LLONG_MIN;
long long pow3[30];

void dfs(int idx, int lim, int v1, int v2, int v3, int m, int t){
    if(idx == lim){
        if(t){
            if(!mpv.count({v2-v1, v3-v2}) || v1 > mpv[{v2-v1, v3-v2}]){
                mpv[{v2-v1, v3-v2}] = v1;
                mpm[{v2-v1, v3-v2}] = m;
            }
        }
        else{
            if(mpv.count({v1-v2, v2-v3})){
                if(mpv[{v1-v2, v2-v3}] + v1 > ansv){
                    ansv = mpv[{v1-v2, v2-v3}] + v1;
                    ansm = pow3[N-min(N, 12)]*mpm[{v1-v2, v2-v3}] + m;
                }
            }
        }
        return;
    }
    dfs(idx+1, lim, v1+arr[idx][0], v2+arr[idx][1], v3, m*3, t);
    dfs(idx+1, lim, v1, v2+arr[idx][1], v3+arr[idx][2], m*3+1, t);
    dfs(idx+1, lim, v1+arr[idx][0], v2, v3+arr[idx][2], m*3+2, t);
}

int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    pow3[0] = 1;
    for(int i = 1; i<=N; i++){
        pow3[i] = pow3[i-1]*3;
    }
    dfs(0, min(12, N), 0, 0, 0, 0, 1);
    dfs(min(12, N), N, 0, 0, 0, 0, 0);
    if(ansv == LLONG_MIN){
        cout << "Impossible" <<endl;
        return 0;
    }
    stack<string> stk;
    for(int i= 0; i<N; i++){
        if(ansm%3 == 0){
            stk.push("LM");
        }
        else if(ansm%3 == 1){
            stk.push("MW");
        }
        else{
            stk.push("LW");
        }
        ansm /= 3;
    }
    while(stk.size()){
        cout << stk.top() << endl;
        stk.pop();
    }
}