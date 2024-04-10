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
    int p[n];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cin.ignore();
    for(int i = 0; i < n; i++)
    {
        int cnt = 0;
        string vow = "aeiouy";
        string s;
        getline(cin, s);
        stringstream ss(s);
        while(ss >> s)
        {
            for(auto c: vow)
                cnt += count(begin(s), end(s), c);
        }
        if(cnt != p[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}