#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;


int main() {
    int m,cur,gcd;
    vi v;
    cin>>m;
    bool flag=0;
    for(int i=0;i<m;i++) {
        cin>>cur;
        v.push_back(cur);
        if(cur%v[0]!=0) flag=1;
    }
    if(flag) cout<<-1<<endl;
    else {
        cout<<2*m<<endl;
        for(int i=0;i<m-1;i++) {
            printf("%d %d ",v[i],v[0]);
        }
        printf("%d %d ",v[m-1],v[0]);
    }

}