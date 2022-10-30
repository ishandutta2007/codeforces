#include <bits/stdc++.h>

using namespace std;

int n, a, d[200001];
bool volt[200001];
bool t[10];
vector<int> v[200001], s;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a;
        v[i].push_back(a);
        if(i>1)v[i].push_back(i-1);
        if(i<n)v[i].push_back(i+1);
    }
    s.push_back(1);
    d[1]=0;
    volt[1]=true;
    for(int i=0;i<s.size();i++) {
        int p=s[i];
        for(int j=0;j<v[p].size();j++) {
            int q=v[p][j];
            if(!volt[q]) {
                volt[q]=true;
                s.push_back(q);
                d[q]=d[p]+1;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    return 0;
}