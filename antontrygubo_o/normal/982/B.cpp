#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    queue<pair<int, int>> intro;
    stack<pair<int, int>> extra;
    pair<int, int> a[n];
    int temp;
    for (int i = 0; i<n; i++) {cin>>temp; a[i] = {temp, i};}
    sort(a, a+n);
    string s;
    cin>>s;
    for (int i = 0; i<n; i++) intro.push(a[i]);
    for (int i = 0; i<2*n; i++)
    {
        if (s[i]=='0')
        {
            pair<int, int> my = intro.front();
            cout<<my.second+1<<' ';
            intro.pop();
            extra.push(my);
        }
        else
        {
            cout<<(extra.top()).second+1<<' ';
            extra.pop();
        }
    }
}