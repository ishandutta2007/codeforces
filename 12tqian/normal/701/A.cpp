#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a;
    int s = 0;
    for(int i = 0; i<n; i++){
        int d;
        cin >> d;
        a.emplace_back(d);
        s += d;
    }
    int vis [105];
    s = s/(n/2);
    for(int i = 0; i<n; i++){
        vis[i] = 0;
    }
   // cout << s<< endl;
    for(int i = 0; i<n; i++){
        if(vis[i] == 1){
            continue;
        }
        vis[i] = 1;
        for(int x = 0; x<n; x++){
            if(vis[x] == 0 && s- a[i] == a[x]){
                vis[x] = 1;
                cout << i +1<< " " << x+1<< endl;
                break;
            }
        }
    }
    return 0;
}