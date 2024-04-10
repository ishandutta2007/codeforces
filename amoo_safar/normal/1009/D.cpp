#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
vector<int> g[100001];
vector<int> g2[100001];
int main(){
    ll n,m;
    cin >> n >>m;
    if(m< n-1) {
        cout << "Impossible";
        return 0;
    }
    ll edge = 0;
    for(int i = 2;i<=n;i++){
        g[i].push_back(1);
        g2[1].push_back(i);
        edge ++;
    }
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<g[i].size();j++){
            for(int k = i+g[i][j];k<=n;k+=i){
                edge++;
                g[k].push_back(i);
                g2[i].push_back(k);
                if(edge >= m){
                    break;
                }
            }
        }
    }
    if(edge < m){
        cout << "Impossible";
        return 0;
    }
    cout << "Possible" << endl;
    for(int i =1;i<=n;i++){
        for(int j =0;j<g2[i].size();j++){
            cout << i << " " << g2[i][j]  << endl;
            m -=1;
            if(m == 0){
                break;
            }
        }
        if(m==0) break;
    }
    cout << endl;
    return 0;
}