#include <bits/stdc++.h>

using namespace std;

int n, q, m, w[20], k=1, most, be;
int t[5000], db[5000];
string s;
int ku[5000][102];
vector<int> ki;

int num(string s) {
    int ki=0;
    for(int i=0;i<n;i++) {
        ki=ki*2+(s[i]-'0');
    }
    return ki;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i=0;i<n;i++) {
        cin >> w[i];
        k*=2;
    }
    for(int i=0;i<k;i++) {
        most=0;
        int ii=i;
        for(int j=0;j<n;j++) {
            if(ii%2==0) t[i]+=w[n-j-1];
            ii/=2;
        }
    }
    for(int i=0;i<m;i++) {
        cin >> s;
        db[num(s)]++;
    }
    for(int i=0;i<k;i++) {
        for(int j=0;j<k;j++) {
            if(t[i^j]<=100) ku[i][t[i^j]]+=db[j];
        }
        for(int j=1;j<=100;j++) {
            ku[i][j]+=ku[i][j-1];
        }
    }
    for(int i=0;i<q;i++) {
        cin >> s >> be;
        int a=num(s);
        ki.push_back(ku[a][be]);
    }
    for(int i=0;i<q;i++) {
        printf("%d\n",ki[i]);
    }
    return 0;
}