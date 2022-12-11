#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main(){
    cin >> N;
    int lst = 0;
    int cnt = 0;
    for(int i = 1; i<=N; i++){
        int n;
        cin >> n;
        if(n != lst){
            v.push_back(cnt);
            cnt = 1;
        }
        else{
            cnt++;
        }
        lst = n;
    }
    v.push_back(cnt);
    int ans = 0;
    for(int i= 1; i<v.size(); i++){
        ans = max(ans, min(v[i], v[i-1]));
    }
    cout << 2*ans << endl;
}