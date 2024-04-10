#include <bits/stdc++.h>

using namespace std;

int n, k, be;
vector<int> ki;

bool l[501][501];

int lehet(int a, int b) {
    if(a<0 || b<0) return false;
    return l[a][b];
}

int main()
{
    cin >> n >> k;
    l[0][0]=true;
    for(int x=0;x<n;x++) {
        cin >> be;
        for(int i=k;i>=0;i--) {
            for(int j=k;j>=0;j--) {
                if(lehet(i-be,j) || lehet(i,j-be)) l[i][j]=true;
            }
        }
    }
    for(int i=0;i<=k;i++) {
        if(l[i][k-i]) ki.push_back(i);
    }
    cout << ki.size() << endl;
    for(int i=0;i<ki.size();i++) cout << ki[i] << " ";
    cout << endl;
    return 0;
}