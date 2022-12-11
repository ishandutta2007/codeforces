#include <bits/stdc++.h>

using namespace std;

int T;
string s;
bool f(vector<int> v){
    int n = 0;
    int mini = 0, maxi = 0;
    pair<pair<int, int>, pair<int, int>> can;
    for(int i = 0; i<v.size(); i++){
        n += v[i];
        if(mini > n){
            mini = n;
            can.first.first = can.first.second = i;
        }
        else if(mini == n){
            can.first.second = i;
        }
        if(maxi < n){
            maxi = n;
            can.second.first = can.second.second = i;
        }
        else if(maxi == n){
            can.second.second = i;
        }
    }
    return ((can.first.second < can.second.first) || (can.second.second < can.first.first));
}

int main(){
    cin >> T;
    while(T--){
        cin >> s;
        vector<int> a, b;
        for(char c : s){
            if(c == 'W'){
                a.push_back(1);
            }
            else if(c == 'S'){
                a.push_back(-1);
            }
            else if(c == 'A'){
                b.push_back(-1);
            }
            else{
                b.push_back(1);
            }
        }
        int maxx = 0, minx = 0, maxy = 0, miny = 0;
        int c = 0;
        for(int n : b){
            c += n;
            maxx = max(maxx, c);
            minx = min(minx, c);
        }
        c = 0;
        for(int n : a){
            c += n;
            maxy = max(maxy, c);
            miny = min(miny, c);
        }
        //cout << maxx << " " << minx << " " << maxy << " " << miny << endl;
        long long ans = 1LL*(maxx-minx+1)*(maxy-miny+1);
        if(f(b)){
            ans = min(ans, 1LL*(maxx-minx)*(maxy-miny+1));
        }
        if(f(a)){
            ans = min(ans, 1LL*(maxx-minx+1)*(maxy-miny));
        }
        cout << ans << endl;
    }
}