#include <bits/stdc++.h>

using namespace std;

bool check_prime(int a)
{
    if(a == 1)
        return 0;
    if((a & 1) == 0 && a != 2)
        return 0;
    for(int i = 3; i * i <= a; i += 2)
        if(a % i == 0)
            return 0;
    return 1;
}

bool check_pal(int a)
{
    string s;
    stringstream ss;
    ss << a;
    ss >> s;
    string st = s;
    reverse(st.begin(), st.end());
    return s == st;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 1180000;
    int p, q;
    cin >> p >> q;
    double mx = 0;
    int pi = 0, pal = 0;
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        pi += check_prime(i);
        pal += check_pal(i);
        if(pi * q <= pal * p)
            ans = i;
    }
    cout << ans << "\n";

    return 0;
}