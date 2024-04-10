#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    string s;
    cin >> s;
    vector<int> v;
    vector<vector<int>> loc = {{1,3},{0,0},{1,0},{2,0},{0,1},{1,1},{2,1},{0,2},{1,2},{2,2}};
    for(int i = 0; i<n; i++){
        int d = (int) s.at(i) - '0';
        v.emplace_back(d);
    }
    int c = 0;
    for(int i = 0; i<10; i++){
        bool good = true;
        int x = loc[i][0];
        int y = loc[i][1];
        for(int a = 1; a<n; a++){
            int x1 = loc[v[a-1]][0];
            int y1 = loc[v[a-1]][1];
            int x2 = loc[v[a]][0];
            int y2 = loc[v[a]][1];
            x = x+(x2-x1);
            y = y+ (y2 - y1);
            bool isTrue = false;
            for(int b = 0; b<10; b++){
                if(loc[b][0] == x && loc[b][1] == y){
                    isTrue = true;
                    break;
                }
            }
            if(!isTrue){
                good = false;
                break;
            }
        }
        if(good == false){
            continue;
        }
        c += 1;
    }
    if(c <= 1){
        cout<< "YES";
    }
    else{
        cout<< "NO";
    }
    return 0;
}