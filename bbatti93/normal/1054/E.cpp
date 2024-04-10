#include <bits/stdc++.h>

using namespace std;

int n, ki, m;
string s1[2][302][302];
int t10[2][302], t11[2][302];
vector<pair<pair<int,int>,pair<int,int> > > v1[2];



int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> s1[0][i][j];
        }
    }
     for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> s1[1][i][j];
            reverse(s1[1][i][j].begin(),s1[1][i][j].end());
        }
     }
   for(int y=0;y<=1;y++) {
        for(int i=1;i<=n;i++) {
            for(int j=2;j<m;j++) {
                int l=s1[y][i][j].size();
                for(int k=l-1;k>=0;k--) {
                    if(s1[y][i][j][k]=='0') {
                        v1[y].push_back({{i,j},{i,1}});
                        t10[y][i]++;
                    } else {
                        v1[y].push_back({{i,j},{i,m}});
                        t11[y][i]++;
                    }
                }
            }
            int j=1;
            int l=s1[y][i][j].size();
            for(int k=l-1;k>=0;k--) {
                if(s1[y][i][j][k]=='0') {
                    int x=i+1;
                    if(x>n) x=1;
                    v1[y].push_back({{i,j},{x,1}});
                    t10[y][x]++;
                } else {
                    v1[y].push_back({{i,j},{i,m}});
                    t11[y][i]++;
                }
            }
            j=m;
            l=s1[y][i][j].size();
            for(int k=l-1;k>=0;k--) {
                if(s1[y][i][j][k]=='1') {
                    int x=i+1;
                    if(x>n) x=1;
                    v1[y].push_back({{i,j},{x,m}});
                    t11[y][x]++;
                } else {
                    v1[y].push_back({{i,j},{i,1}});
                    t10[y][i]++;
                }
            }
        }
        for(int i=2;i<=n;i++) {
            for(int j=0;j<t10[y][i];j++) {
                v1[y].push_back({{i,1},{1,1}});
            }
            for(int j=0;j<t11[y][i];j++) {
                v1[y].push_back({{i,m},{1,m}});
            }
        }
    }
    cout << v1[0].size()+v1[1].size() << endl;
    for(int i=0;i<v1[0].size();i++) {
        cout << v1[0][i].first.first << " " << v1[0][i].first.second << " " << v1[0][i].second.first << " " << v1[0][i].second.second << "\n";
    }
    int l=v1[1].size();
    for(int i=l-1;i>=0;i--) {
        cout << v1[1][i].second.first << " " << v1[1][i].second.second << " " << v1[1][i].first.first << " " << v1[1][i].first.second << "\n";
    }
    cout << endl;
    return 0;
}