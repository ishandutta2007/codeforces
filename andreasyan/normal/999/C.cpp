#include <bits/stdc++.h>
using namespace std;
const int N=400005;

vector<int> a[26];

int n,k;
char b[N];

bool c[N];
int main()
{
    cin>>n>>k;
    cin>>b;
    for(int i=0;i<n;++i)
    {
        a[b[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;++i)
        reverse(a[i].begin(),a[i].end());
    int i=0;
    while(k--)
    {
        while(a[i].empty())
            ++i;
        c[a[i].back()]=true;
        a[i].pop_back();
    }
    for(int i=0;i<n;++i)
        if(!c[i])
            cout<<b[i];
    cout<<endl;
    return 0;
}