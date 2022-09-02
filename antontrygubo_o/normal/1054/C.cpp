#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll p = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int l[n];
    int r[n];
    for (int i = 0; i<n; i++) cin>>l[i];
    for (int i = 0; i<n; i++) cin>>r[i];
    int cool[n];
    set<int> a;
    for (int i = 0; i<n; i++) a.insert(l[i]+r[i]);
    map<int, int> my;
    int idx = n;
    for (auto it = a.begin(); it!=a.end(); it++) 
    {
        my[*it] = idx;
        idx--;
    }
    
    int res[n];
    for (int i = 0; i<n; i++) res[i] = my[l[i]+r[i]];
    
    for (int i = 0; i<n; i++)
    {
        int counter = 0;
        for (int j = 0; j<i; j++) if (res[j]>res[i]) counter++;
        if (counter!=l[i]) {cout<<"NO"; return 0;}
        counter = 0;
        for (int j = i+1; j<n; j++) if (res[j]>res[i]) counter++;
        if (counter!=r[i]) {cout<<"NO"; return 0;}
    }
    cout<<"YES"<<endl;
    for (int i = 0; i<n; i++) cout<<res[i]<<' ';
    
    
    
     
}