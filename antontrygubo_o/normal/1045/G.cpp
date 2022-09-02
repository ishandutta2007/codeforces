#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct robot
{
    ll x;
    ll r;
    ll iq;
};

bool sortrobot(robot a, robot b)
{
    if (a.r!=b.r) return a.r>=b.r;
    return a.x>=b.x;
}

struct fenwick
{
    vector<int> fenw;
    int summa(int r)
    {
        if (r<0) return 0;
        int res = 0;
        while (r>=0)
        {
            res+=fenw[r];
            r=(r&(r+1))-1;
        }
        return res;
    }

    int summainterval(int l, int r)
    {
        if (l>r) return 0;
        return summa(r)-summa(l-1);
    }
    
    void update(int pos, int val)
    {
        for (int i = pos; i<fenw.size(); i=(i|(i+1))) fenw[i]+=val;
    }

    void init(int n)
    {
        fenw.resize(n);
    }
};

int k;

unordered_map<int, vector<int>> iqpoints;
    
unordered_map<int, fenwick> myfenw;
    
set<int> differentiq;

vector<int> dif_iq;
    
void upd(robot temp)
{
    int l = int(lower_bound(iqpoints[temp.iq].begin(), iqpoints[temp.iq].end(), temp.x) - iqpoints[temp.iq].begin());
    myfenw[temp.iq].update(l, 1);
}

int getinfo(robot temp)
{
    int res = 0;
    for (int Iq = temp.iq-k; Iq<=temp.iq+k; Iq++) if (differentiq.find(Iq)!=differentiq.end())
    {
        int l = temp.x-temp.r;
        int r = temp.x+temp.r;
        int l1 = int(lower_bound(iqpoints[Iq].begin(), iqpoints[Iq].end(), l) - iqpoints[Iq].begin());
        int r1 = int(upper_bound(iqpoints[Iq].begin(), iqpoints[Iq].end(), r) - iqpoints[Iq].begin());
        r1--;
        res+=myfenw[Iq].summainterval(l1, r1);
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n>>k;
    vector<robot> a(n);
    for (int i = 0; i<n; i++) 
    //{a[i].x = i; a[i].r = 1000000; a[i].iq = i%22;}
    cin>>a[i].x>>a[i].r>>a[i].iq;
    sort(a.begin(), a.end(), sortrobot);
    for (int i = 0; i<n; i++) differentiq.insert(a[i].iq);
    for (auto it = differentiq.begin(); it!=differentiq.end(); it++) dif_iq.push_back(*it);
    for (int i = 0; i<n; i++) iqpoints[a[i].iq].push_back(a[i].x);
    for (int i = 0; i<dif_iq.size(); i++) sort(iqpoints[dif_iq[i]].begin(), iqpoints[dif_iq[i]].end());
    for (int i = 0; i<dif_iq.size(); i++)
    {
        myfenw[dif_iq[i]].init(iqpoints[dif_iq[i]].size());
    }
    ll result = 0;
    for (int i = 0; i<n; i++)
    {
        result+=getinfo(a[i]);
        upd(a[i]);
    }
    cout<<result;
}