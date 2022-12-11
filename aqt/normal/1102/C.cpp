#include <bits/stdc++.h>

using namespace std;

int N,x,y;
vector<int> v;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> x >> y;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    if(x > y){
        cout << N << endl;
        return 0;
    }
    else{
        int cnt = 0;
        for(int i = 0; i<N; i+=2){
            if(v[i] <= x){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}