#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
static vector<vector<int>> adj;
static int dp[MAX];
static int type[1000];
int bin(int lo, int x){
    int l = 0;
    int r = adj[x].size() - 1;
    int index = 1000000;
    while(l<= r){
        int m = (l + r)/2;
        if(adj[x][m] < lo){
            l = m+1;
        }
        else{
            index = min(adj[x][m], index);
            r = m-1;
        }
    }
    if(index == 1000000){
        return -1;
    }
    return index;
}
int main(){
    vector<int> t;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i =0 ; i<1000; i++){
        vector<int> temp;
        adj.emplace_back(temp);
    }
    for(int i = 0; i<n; i++){
        int x = s[i] - 'A';
        adj[x].emplace_back(i);
        //cout << x << " x" << endl;
        type[x] = 1;
        t.emplace_back(x);
    }
    int types = 0;
    for(int i = 0; i<1000; i++){
        types += type[i];
    }
    map<int, int> m;
    int c = 0;
    int ans = -1;
    for(int i = 0; i<n; i++){
        map<int, int>:: iterator it = m.find(t[i]);
        if(it== m.end()){
            m[t[i]] = 1;
            c += 1;
        }
        if(c == types){
            dp[0] = i;
            break;
        }
    }
    ans = dp[0] + 1;
    //cout << ans << " ans" << endl;
    for(int i = 1; i<=n- types; i++){
        int r = t[i-1];
        int stop = dp[i-1];
        int index = bin(i, r);
       //cout << i << " " << r << " " << index << " " << stop <<  endl;
        if(index == -1){
            break;
        }
        if(index <=stop){
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = index;
        }
        ans = min(ans, dp[i] - i + 1);
    }
    cout <<ans;
    return 0;
}