#include <bits/stdc++.h>

using namespace std;

int n, ki, t[250001], most=0;
priority_queue<int> q, d;
vector<int> v;
long long lnko(long long a, long long b) {
    if(b>a) return lnko(b,a);
    if(b==0) return a;
    return lnko(b, a%b);
}

long long lkkt(long long a, long long b) {
    return a*b/lnko(a,b);
}
int main()
{
    cin >> n;
    for(int i=0;i<n*n;i++) {
        cin >> t[i];
        q.push(t[i]);
    }
    while(!q.empty()) {
        while(!d.empty()&& (d.top()==q.top())) {
            d.pop();
            q.pop();
        }
        if(q.empty()) break;
        int a=q.top();
        cout << a << " ";
        q.pop();
        v.push_back(a);
        for(int i=0;i<v.size()-1;i++) {
            d.push((int)lnko(a, v[i]));
            d.push((int)lnko(a, v[i]));
        }
    }
    cout << endl;
    return 0;
}