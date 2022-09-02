#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

const ll p = 78294349;

int mul(int a, int b) {
    return (1LL * a * b) % p;
}

int add(int a, int b) {
    int s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<int> counter(m+1); 
    vector<int> a(n);
    get(a);
    for (int i = 0; i<n; i++) counter[a[i]]++;
    a.clear();

    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(3, vector<int>(3)));
    for (int i = 1; i<=m; i++)
    {
        for (int l1 = 0; l1<=2; l1++)
        for (int m1 = 0; m1<=2; m1++)
        {
            for (int r1 = 0; r1<=2; r1++) if (l1 + m1 + r1<=counter[i])
            {
                if (i-2>=0&&r1>counter[i-2]) continue;
                if (i-1>=0&&r1 + l1>counter[i-1]) continue;
                if (i+1<=m&&l1 + m1>counter[i+1]) continue;
                if (i+2<=m&&m1>counter[i+2]) continue;
                dp[i][l1][m1] = max(dp[i][l1][m1], dp[i-1][r1][l1] + r1 + (counter[i]-l1-m1-r1)/3);
            }
        }
    }
    int maxx = 0;
    for (int l = 0; l<=2; l++)
    for (int r = 0; r<=2; r++)
    maxx = max(maxx, dp[m][l][r]);
    cout<<maxx;
    
}