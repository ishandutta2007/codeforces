#include <bits/stdc++.h>

using namespace std;

bool volt[2][1001];
vector<int> v[2], t[2], maxi;
int ki=1000000, a, b, n;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    t[0].resize(300000,1000000);
    t[1].resize(300000,1000000);
    maxi.resize(2,0);
    t[0][0]=t[1][0]=0;
    cin >> a >> n;
    for(int i=0;i<n; i++) {
        cin >> b;
        b-=a;
        if(b>0) if(!volt[0][b]) {
            volt[0][b]=true;
            v[0].push_back(b);
            if(b>maxi[0]) maxi[0]=b;
        }
        if(b<0) if(!volt[1][-b]) {
            volt[1][-b]=true;
            v[1].push_back(-b);
            if(-b>maxi[1]) maxi[1]=-b;
        }
        if(b==0) {
            cout << 1 << endl;
            return 0;
        }
    }
    if(v[0].size()==0 || v[1].size()==0) {
        cout << -1 << endl;
        return 0;
    }
    for(int i=1; i/maxi[0]+i/maxi[1]<ki; i++) {
        for(int l=0; l<2; l++) {
            for(int j=0; j<v[l].size(); j++) {
                if(v[l][j]>i) continue;
                if(t[l][i-v[l][j]]+1<t[l][i]) {
                    t[l][i]=t[l][i-v[l][j]]+1;
                }
            }
        }
        if(t[0][i]+t[1][i]<ki) ki=t[0][i]+t[1][i];
    }
    cout << ki << endl;
    return 0;
}