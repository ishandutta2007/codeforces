#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<vector<int>> a(1000000, vector<int>(2));

void count(string s)
{
    vector<int> ans(3);
    ans[0] = 1;
    ans[1] = 1;
    int n = s.length();
    int op = 0;
    int cl = 0;
    for (int i = 0; i<n; i++) 
    {
        if (s[i]=='(') op++; else cl++;
        if (op<cl) ans[0] = 0;
    }
    ans[2] = cl-op;
    if (ans[2]<0) ans[2]+=1000000;
    op = 0;
    cl = 0;
    for (int i = n-1; i>=0; i--) 
    {
        if (s[i]=='(') op++; else cl++;
        if (op>cl) ans[1] = 0;
    }
    a[ans[2]][0]+=ans[0];
    a[ans[2]][1]+=ans[1];
}


int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    string s;
    for (int i = 0; i<n; i++)
    {
        cin>>s; count(s);
    }
    
    int answer = 0;
    answer+=a[0][0]/2;
    for (int i = 1; i<500000; i++) 
    {
        answer+=min(a[i][0], a[1000000-i][1]);
        answer+=min(a[i][1], a[1000000-i][0]);
    }
    cout<<answer;
}