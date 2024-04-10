#include <bits/stdc++.h>
using namespace std;
struct film {
    int b, c, pos;
};

int main()
{
    ios_base::sync_with_stdio(0);
    //ifstream cin("input.txt");
    int n;
    cin>>n;
    map<int,int> cnt;
    for(int i=0,lg; i<n; i++) { cin>>lg; cnt[lg]++; }
    int m;
    cin>>m;
    film q[m];
    for(int i=0,lg; i<m; i++) { cin>>lg; q[i].b=(cnt[lg]?-cnt[lg]:0); q[i].pos=i; }
    for(int i=0,lg; i<m; i++) { cin>>lg; q[i].c=(cnt[lg]?-cnt[lg]:0); }
    sort(q,q+m,[](film f, film s){ return f.b<s.b||(f.b==s.b&&f.c<s.c); });
    cout<<q[0].pos+1;
    return 0;
}