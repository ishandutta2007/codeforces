#include <bits/stdc++.h>

using namespace std;
int n, a;
set<pair<int,int> > s;
int main()
{
    cin >> n;
    cin >> a;
    pair<int,int> b(0,0),c(1000000001,0), d(a,1);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    for(int i=2;i<=n;i++) {
        cin >> a;
        pair<int,int> p(a,i);
        int x=s.lower_bound(p)->second, y=(--(s.lower_bound(p)))->second;
        int u=s.lower_bound(p)->first, v=(--(s.lower_bound(p)))->first;
        cout << (x>y?u:v) << " ";
        s.insert(p);
    }
    return 0;
}