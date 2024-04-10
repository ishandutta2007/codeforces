#include <bits/stdc++.h>

using namespace std;

int n, ki, p[100001], c[100001];
vector<int> v[100001];
int e[100001];

void dfsc(int a) {
    for(int i=0;i<v[a].size();i++) {
        dfsc(v[a][i]);
        c[a]+=c[v[a][i]];
    }
    c[a]++;
}

void dfse(int a) {
    for(int i=0;i<v[a].size();i++) {
        e[v[a][i]]=e[a]+(c[a]-c[v[a][i]]-1)+2;
        dfse(v[a][i]);
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n-1;i++) {
        cin >> p[i];
        v[p[i]].push_back(i+2);
    }
    dfsc(1);
    e[1]=2;
    dfse(1);
    for(int i=1;i<=n;i++) {
        cout << e[i]/2.0 << " ";
    }
    cout << endl;
    return 0;
}