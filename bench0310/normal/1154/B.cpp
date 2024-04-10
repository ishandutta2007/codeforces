#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    vector<int> v;
    for(auto x:s) v.push_back(x);
    if(v.size()==1) cout << 0 << endl;
    else if(v.size()==2)
    {
        if((v[1]-v[0])&1) cout << v[1]-v[0] << endl;
        else cout << (v[1]-v[0])/2 << endl;
    }
    else if(v.size()==3&&(v[2]-v[1])==(v[1]-v[0]))
    {
        cout << v[1]-v[0] << endl;
    }
    else cout << -1 << endl;
    return 0;
}