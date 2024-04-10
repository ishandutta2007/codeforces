#include <bits/stdc++.h>

using namespace std;

int n, k;
class csop {
public:
    vector<int> mini, maxi;
    int t;
    csop() {}
    operator <(const csop& b) const {
        return mini[0]<b.mini[0];
    }
    void add(const csop& b) {
        t+=b.t;
        for(int i=0;i<mini.size();i++) {
            if(b.mini[i]<mini[i]) mini[i]=b.mini[i];
            if(b.maxi[i]>maxi[i]) maxi[i]=b.maxi[i];
        }
    }
    bool comp(const csop& b) const {
        bool l1=false, l2=false;
        for(int i=0;i<mini.size();i++) {
            if(b.mini[i]<maxi[i]) l1=true;
            if(b.maxi[i]>mini[i])  l2=true;
        }
        return l1&&l2;
    }
};
set<csop> s;

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        csop cs;
        cs.t=1;
        for(int j=0;j<k;j++) {
            int a;
            cin >> a;
            cs.mini.push_back(a);
            cs.maxi.push_back(a);
        }
        set<csop>::iterator it=s.lower_bound(cs);
        while(true) {
            if(it!=s.end() && it->comp(cs)) {
                set<csop>::iterator jt=it;
                it++;
                cs.add(*jt);
                s.erase(jt);
                continue;
            }
            if(it!=s.begin())it--;
            if(it!=s.end() && it->comp(cs)) {
                set<csop>::iterator jt=it;
                it++;
                cs.add(*jt);
                s.erase(jt);
                continue;
            }
            break;
        }
        s.insert(cs);
        set<csop>::reverse_iterator xt=s.rbegin();
        cout << xt->t << endl;
    }
    return 0;
}