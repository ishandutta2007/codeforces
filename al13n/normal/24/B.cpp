#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)
#define pb push_back

vector<int> v1[1100];
vector<int> v2[1100];
int cnt[1100][60];
int pts[1100];
map<string,int> s2i;
vector<string> i2s;
const int plpts[]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int main(){
#ifdef __ASD__
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int q;
    cin>>q;
    forn(i,q){
        int n;
        cin>>n;
        forn(i,n){
            string s;
            cin>>s;
            int p;
            if(!s2i.count(s)){
                p=i2s.size();
                s2i[s]=p;
                i2s.pb(s);
            }else
                p=s2i[s];
            if(i<10)
                pts[p]+=plpts[i];
            ++cnt[p][i];
        }
    }
    int n=i2s.size();
    forn(i,n){
        v1[i].pb(pts[i]);
        forn(j,50)
            v1[i].pb(cnt[i][j]);
        v1[i].pb(i);

        v2[i].pb(cnt[i][0]);
        v2[i].pb(pts[i]);
        for(int j=1;j<50;++j)
            v2[i].pb(cnt[i][j]);
        v2[i].pb(i);
    }
    sort(v1,v1+n);
    sort(v2,v2+n);
    reverse(v1,v1+n);
    reverse(v2,v2+n);

    cout<<i2s[v1[0].back()]<<endl<<i2s[v2[0].back()];

    return 0;
}