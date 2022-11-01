#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n+1,0);
    auto out=[](){cout << "NO\n"; exit(0);};
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a>b) swap(a,b);
        if(b!=n||a==b) out();
        c[a]++;
    }
    vector<int> v;
    vector<int> zero;
    for(int i=n-1;i>=1;i--) if(c[i]==0) zero.push_back(i);
    for(int i=1;i<=n-1;i++)
    {
        if(c[i]==0) continue;
        v.push_back(i);
        c[i]--;
        while(c[i]--)
        {
            if(zero.empty()||zero.back()>i) out();
            v.push_back(zero.back());
            zero.pop_back();
        }
    }
    v.push_back(n);
    cout << "YES\n";
    for(int i=0;i<n-1;i++) cout << v[i] << " " << v[i+1] << "\n";
    return 0;
}