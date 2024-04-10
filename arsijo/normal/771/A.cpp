#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
vector<int> v[N];
int use[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        v[l].pb(r);
        v[r].pb(l);
    }
    int k=0;
    for (int i=1; i<=n; i++)
        if (use[i]==0)
        {
            k++;
            use[i]=k;
            for (int j=0; j<v[i].size(); j++)
            {
                int to=v[i][j];
                if (use[to]!=0) {cout<<"NO"<<endl; return 0;}
                use[to]=k;
            }
            for (int j=0; j<v[i].size(); j++)
            {
                int to=v[i][j];
                if (v[to].size()!=v[i].size()) {cout<<"NO"<<endl; return 0;}
                for (int p=0; p<v[to].size(); p++)
                if (use[v[to][p]]!=k) {cout<<"NO"<<endl; return 0;}
            }
        }
    cout<<"YES"<<endl;
}