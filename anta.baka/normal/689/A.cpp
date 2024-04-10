#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool t[4][3];
    for(int i=0; i<4; i++)
        for(int j=0; j<3; j++)
            t[i][j] = false;
    for(int i=0; i<n; i++) {
        char c;
        cin >> c;
        int u = c - '0';
        if(!u) { t[3][1] = true; continue; }
        u--;
        t[u/3][u%3] = true;
    }
    int g[][2] = {0,1, 1,0, -1,0, 0,-1};
    for(int k=0; k<4; k++) {
        bool can = true;
        for(int i=0; i<4; i++)
            for(int j=0; j<3; j++)
                if(t[i][j]) {
                    int ii = i+g[k][0], jj = j+g[k][1];
                    if(ii>=0&&ii<4&&jj>=0&&jj<3&&!((ii==3&&jj==0)||(ii==3&&jj==2)))
                        continue;
                    can = false;
                }
        if(can) {
            cout<<"NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}