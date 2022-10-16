#include <bits/stdc++.h>
using namespace std;
static vector<int> l;
static vector<int> r;
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        l.emplace_back(x);
        r.emplace_back(y);
    }
    string fin = "";
    for(int i = 0; i<n; i++){
        if(i%2 == 0){
            fin += "0";
        }
        else{
            fin += "1";
        }
    }
    cout << fin;
    return 0;
}