#include <bits/stdc++.h>

using namespace std;

long long n, k, m;
vector<pair<int,int> > v, u;
int a, b, c;


int main()
{
    cin >> n >> k >> m;
    a=n;
    for(int i=0;i<n;i++) {
        int w;
        cin >> w;
        if(v.size()>0 && v.back().first==w) {
            v.back().second++;
            if(v.back().second==k) {
                v.pop_back();
                a-=k;
            }
        } else v.push_back({w,1});
    }
    u=v;
    int b=a;
    int x=0, y=u.size()-1;
    while(x<y){
        if(u[x].first==u[y].first) {
            if(u[x].second+u[y].second==k) {
                x++;
                y--;
                b-=k;
            } else {
                if(u[x].second+u[y].second>k) b-=k;
                break;
            }
        } else {break;}
    }
    long long r=m*b;
    a-=b;
    if(x==y) {
        r=r%k;
        if(r==0) a=0;
    }
    cout << a+r << endl;
    return 0;
}