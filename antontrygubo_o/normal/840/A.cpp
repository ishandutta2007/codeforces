#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void print(vector<int> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

const ll p = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) cin>>a[i];
    vector<pair<int, int>> b(n);
    for (int i = 0; i<n; i++) 
    {
        cin>>b[i].first; b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    
    vector<int> answer(n);
    for (int i = 0; i<n; i++) answer[b[i].second] = a[n-1-i];
    for (int i = 0; i<n; i++) cout<<answer[i]<<' ';
    
    

}