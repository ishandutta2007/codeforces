#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>> a(n-1);
    vector<int> counter(n, 0);
    for (int i = 0; i<n-1; i++) 
    {
        cin>>a[i].first>>a[i].second; if (a[i].first>a[i].second) swap(a[i].first, a[i].second); 
        if (a[i].second!=n) {cout<<"NO"; return 0;} 
        counter[a[i].first]++;
    } 
    vector<int> unused;
    for (int i = n-1; i>0; i--) if (counter[i]==0) unused.push_back(i);
    /*
    for (int i = 0; i<unused.size(); i++) cout<<unused[i]<<' ';
    cout<<endl;
    */
    vector<int> answer;
    answer.push_back(n);
    int idx = 0;
    for (int i = n-1; i>0; i--)
    {
        if (counter[i]!=0)
        {
            if (idx+counter[i]-1>unused.size()) {cout<<"NO"; return 0;}
            for (int j = 0; j<counter[i]-1; j++)
        {
            answer.push_back(unused[idx]); if (unused[idx]>i) {cout<<"NO"; return 0;} idx++;
        }
        answer.push_back(i);}
    }
    
    for (int j = idx; j<unused.size(); j++) answer.push_back(unused[j]);
    
    cout<<"YES"<<endl;
    for (int i = 0; i<n-1; i++) cout<<answer[i]<<' '<<answer[i+1]<<endl;
}