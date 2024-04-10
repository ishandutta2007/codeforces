#include <iostream>
#include <vector>

using namespace std;

bool jo, hibas[100001];
int n, m, ki,a,b, volt[100001], t[100001], tdb;
vector<int> v[100001],v2[100001];

void mely2(int p) {
    volt[p]=1;
    for(int i=0;i<v[p].size(); i++) {
        if(volt[v[p][i]]==0) mely2(v[p][i]);
    }
    t[p]=tdb--;
}

void mely(int p) {
    if(hibas[p]) jo=false;
    volt[p]=1;
    for(int i=0;i<v2[p].size(); i++) {
        if(volt[v2[p][i]]==0) mely(v2[p][i]);
    }
}

int main()
{
    cin >> n >> m;
    ki=n;
    tdb=n;
    for(int i=1; i<=m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v2[b].push_back(a);
        v2[a].push_back(b);
    }
    for(int i=1; i<=n; i++) volt[i]=0;
    for(int i=1; i<=n; i++) {
        if(!volt[i]) {
            mely2(i);
        }
    }
    for(int i=1; i<=n; i++) volt[i]=0;
    for(int i=1; i<=n; i++) hibas[i]=false;
    for(int i=1;i<=n; i++) {
        for(int j=0;j<v[i].size(); j++) {
            if(t[i]>t[v[i][j]]) hibas[i]=true;
        }
    }
    for(int i=1; i<=n; i++) {
        if(!volt[i]) {
            jo=true;
            mely(i);
            if(jo) ki--;
        }
    }
    cout << ki << endl;
    return 0;
}