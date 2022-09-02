#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int temp;
    int maxx = -1;
    vector<int> p(n);
    for (int i = 0; i<n; i++) cin>>p[i];
    vector<int> answers(n);
    for(int i = 0; i<n; i++)
    {
        maxx = max(maxx, p[n-i-1]);
        answers[n-1-i] = maxx-i;
    }
    for (int i = 0; i<n; i++) cout<<answers[i]<<' ';
    cout<<1;
}