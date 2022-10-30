#include <bits/stdc++.h>

using namespace std;

priority_queue<int> ma, ra;
priority_queue<int, vector<int>, greater<int> > mi, ri;

int n, t[100001];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> t[i];
    int maxi=0, a=-1;
    for(int b=0; b<n; b++) {
        mi.push(t[b]);
        ma.push(t[b]);
        while(ma.top()>mi.top()+1) {
            a++;
            ri.push(t[a]);
            ra.push(t[a]);
            while(!ri.empty() && ri.top()==mi.top()) {
                ri.pop();
                mi.pop();
            }
            while(!ra.empty() && ra.top()==ma.top()) {
                ra.pop();
                ma.pop();
            }
        }
        if(b-a>maxi) {
            maxi=b-a;
        }
    }
    cout << maxi << endl;

    return 0;
}