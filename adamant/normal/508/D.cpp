#include <bits/stdc++.h>

using namespace std;

const int maxn = 26 + 26 + 10;

map<int, string> rec;

int get(char c1, char c2)
{
    char t1 = c1, t2 = c2;
    if(isdigit(c1)) c1 = c1 - '0';
    if(islower(c1)) c1 = c1 - 'a' + 10;
    if(isupper(c1)) c1 = c1 - 'A' + 36;
    if(isdigit(c2)) c2 = c2 - '0';
    if(islower(c2)) c2 = c2 - 'a' + 10;
    if(isupper(c2)) c2 = c2 - 'A' + 36;
    int ret = (int) c1 * maxn + c2;
    rec[ret] = "";
    rec[ret] += t1;
    rec[ret] += t2;
    return ret;
}

map<int, int> g[maxn * maxn], gt[maxn * maxn], used[maxn * maxn];

void fail()
{
    cout << "NO\n";
    exit(0);
}

vector<int> ans;


void recover(int v, int p = -1)
{
    if(p != -1 && used[v][p] == g[p][v]) return;
    used[v][p]++;
    for(auto it: g[v])
        recover(it.first, v);
    ans.push_back(v);
}

main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string x[n];
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        g[get(x[i][0], x[i][1])][get(x[i][1], x[i][2])]++;
        gt[get(x[i][1], x[i][2])][get(x[i][0], x[i][1])]++;
    }
    int cnt = 0;
    vector<int> in, out, num;
    for(int i = 0; i < maxn * maxn; i++)
    {
        int a = 0, b = 0;
        for(auto it: g[i])
            a += it.second;
        for(auto it: gt[i])
            b += it.second;
        if(a != b)
            in.push_back(b),
            out.push_back(a),
            num.push_back(i);
    }
    if(in.size() != 0 && in.size() != 2)
        fail();
    if(in.size() == 2)
    {
        if(in[0] == out[0] + 1 && in[1] == out[1] - 1);
        else if(in[0] == out[0] - 1 && in[1] == out[1] + 1);
        else fail();
    }
    if(num.size())
    {
        if(in[0] < out[0])
            recover(num[0]);
        else
            recover(num[1]);
    }
    else
    {
        for(int i = 0; i < maxn * maxn; i++)
        {
            if(g[i].size())
            {
                recover(i);
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    string rr;
    rr += rec[ans[0]][0];
    for(auto it: ans)
        rr += rec[it][1];
    if(rr.size() == n + 2)
        cout << "YES\n" << rr << "\n";
    else
        fail();
}