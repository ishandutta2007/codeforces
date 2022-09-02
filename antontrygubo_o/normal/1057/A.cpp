#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{

    int n;
    cin>>n;
    vector<int> a(n+1);
    for (int i = 2; i<=n; i++) cin>>a[i];
    vector<int> answer;
    int idx = n;
    while (idx!=1)
    {
        answer.push_back(idx); idx = a[idx];
    }
    answer.push_back(1);
    reverse(answer.begin(), answer.end());
    for (int i = 0; i<answer.size(); i++) cout<<answer[i]<<' ';
}