#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin>>n>>q;
    vector<int> a(n, 0);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) if (a[i]==0) a[i]=q+1;
    
    vector<int> first(q+1, -1);
    vector<int> last(q+1, -1);
    
    
    for (int i = 0; i<n; i++) if (a[i]<=q&&first[a[i]]==-1) first[a[i]] = i;
    for (int i = n-1; i>=0; i--)  if (a[i]<=q&&last[a[i]]==-1) last[a[i]] = i;
    
    bool check = true;
    set<int> opened;
    opened.insert(0);
    for (int i = 0; i<n; i++)
    {
        auto t = opened.end();
        t--;
        if (a[i]<*t) check = false;
        if (i==first[a[i]]) opened.insert(a[i]);
        if (i==last[a[i]]) opened.erase(a[i]);
    }
    /*for (int i = 1; i<=q; i++)
    {
        if (first[i]!=-1) if (sum(1, 0, int(a.size())-1, first[i], last[i])<i) {check = false;}
    }*/
    if (!check) {cout<<"NO"; return 0;}
    int counter = 0;
    for (int i = 0; i<n; i++) if (a[i]==q+1) counter++;
    if (counter==0&&first[q]==-1) {cout<<"NO"; return 0;}
    cout<<"YES"<<endl;
    check = false;
    for (int i = 0; i<n; i++) if (a[i]!=q+1) check = true;
    if (!check) {for (int i = 0; i<n; i++) cout<<q<<' '; return 0;}
    
    int idx = 0;
    while (a[idx]==q+1) idx++;
    int current = a[idx];
    bool good = true;
    if (counter!=0&&first[q]==-1) good = false;
    for (int i = 0; i<=idx; i++) {if (a[i]==q+1&&!good) {cout<<q<<' '; good = true;} else cout<<a[idx]<<' ';}
    for (int i = idx+1; i<n; i++)
    {
        if (a[i]!=q+1) {cout<<a[i]<<' '; current = a[i];}
        else {if (!good) {good = true; cout<<q<<' ';} else cout<<current<<' ';}
    }

}