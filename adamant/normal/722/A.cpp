#include<bits/stdc++.h>

using namespace std;

string tim(int h, int m)
{
    stringstream ss;
    ss << setfill('0') << setw(2) << h << ":";
    ss << setfill('0') << setw(2) << m;
    return ss.str();
}

int dist(string a, string b)
{
    int z = 0;
    for(int i = 0; i < a.size(); i++)
        z += a[i] != b[i];
    return z;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string a;
    cin >> a;
    string b = "";
    for(int h = (n == 12); h < n + (n == 12); h++)
        for(int m = 0; m < 60; m++)
    {
        string t = tim(h, m);
        if(b.empty() || dist(t, a) < dist(b, a))
            b = t;
    }
    cout << b << endl;
    return 0;
}