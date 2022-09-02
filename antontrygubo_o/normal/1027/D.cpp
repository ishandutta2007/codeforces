#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vector<int> c(n);
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>c[i];
    for (int i = 0; i<n; i++) {cin>>a[i]; a[i]--;}
    
    vector<int> where(n, -1);
    ll summ = 0;
    for (int i = 0; i<n; i++) if (where[i]==-1)
    {
        int i1 = i;
        int i2 = i;
        while (where[i2]==-1) {where[i2] = i1; i2 = a[i2];}
        if (where[i2]==i1)
        {
            int minn = c[i2];
            int idx = i2;
            i2 = a[i2];
            while (i2!=idx) {minn = min(minn, c[i2]); i2 = a[i2];}
            summ+=minn;
        }
        
    }
    cout<<summ;
}