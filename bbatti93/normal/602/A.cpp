#include <bits/stdc++.h>

using namespace std;

int div2(vector<int>& a, int b) {
    int r=0;
    for(int i=0;i<a.size();i++) {
        a[i]+=r*b;
        r=a[i]%2;
        a[i]/=2;
    }
    return r;
}

bool null(vector<int> a) {
    bool ki=true;
    for(int i=0;i<a.size();i++) if(a[i]) ki=false;
    return ki;
}

vector<int> a1, a2, k1, k2;
int n1, n2, b1, b2;


int main()
{
    cin >> n1 >> b1;
    for(int i=0;i<n1;i++) {
        int be;
        cin >> be;
        a1.push_back(be);
    }
    while(!null(a1)) {
        int r=div2(a1,b1);
        k1.push_back(r);
    }
    cin >> n2 >> b2;
    for(int i=0;i<n2;i++) {
        int be;
        cin >> be;
        a2.push_back(be);
    }
    while(!null(a2)) {
        int r=div2(a2,b2);
        k2.push_back(r);
    }
    if(k1.size()>k2.size()) {
        cout << '>' << endl;
        return 0;
    }
    if(k1.size()<k2.size()) {
        cout << '<' << endl;
        return 0;
    }
    for(int i=k1.size()-1;i>=0;i--) {
        if(k1[i]>k2[i]) {
            cout << '>' << endl;
            return 0;
        }
         if(k1[i]<k2[i]) {
            cout << '<' << endl;
            return 0;
        }
    }
    cout << '=' << endl;
    return 0;
}