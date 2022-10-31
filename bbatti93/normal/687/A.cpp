#include <bits/stdc++.h>

using namespace std;

int n, m, ki, kekdb;
vector<int> v[100001], keki, piki;
bool volt[100001], kek[100001], baj;

void bejar(int a, bool ke) {
    volt[a]=true;
    kek[a]=ke;
    for(int i=0;i<v[a].size();i++) {
        int p=v[a][i];
        if(!volt[p]) bejar(p,!ke);
        else if(kek[p]==ke) baj=true;
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int be1,be2;
        cin >> be1 >> be2;
        v[be1].push_back(be2);
        v[be2].push_back(be1);
    }
    for(int i=1;i<=n;i++) {
        if(!volt[i]) bejar(i, true);
    }
    if(baj) cout << -1 << endl;
    else {
        for(int i=1;i<=n;i++) if(kek[i]) keki.push_back(i);
        else piki.push_back(i);
        cout << keki.size() << endl;
        for(int i=0;i<keki.size();i++) cout << keki[i] << " ";
        cout << endl;
        cout << piki.size() << endl;
        for(int i=0;i<piki.size();i++) cout << piki[i] << " ";
        cout << endl;
    }
    return 0;
}