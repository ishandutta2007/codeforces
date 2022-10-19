#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;

int n, a[N];
map <int, vector <int> > m;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int u;
        cin >> u;
        m[n-u].push_back(i);
    }
    for (auto e: m){
        if (e.second.size()%e.first) return cout << "Impossible \n", 0;
    }
    cout << "Possible" << endl;
    int nColor=0;
    for (auto e: m){
        int u=e.second.size(), v=e.first;
        for (auto f: e.second){
            if (u%v==0) nColor++;
            a[f]=nColor;
            u--;
        }
    }
    for (int i=1; i<=n; i++)
        cout << a[i] << " ";
}