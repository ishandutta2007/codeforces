#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(auto &a)
{
    for (auto s: a) cout<<s<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

ll p = 1e9 + 7;

ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

mt19937 rnd(228);


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;

    vector<double> x(n+2);
    for (int i = 0; i<n+2; i++) cin>>x[i];
    vector<double> d(n+2);
    for (int i = 1; i<=n; i++) cin>>d[i];
    d[0] = x[n+1];
    d[n+1] = x[n+1];
    
    vector<int> left_stand(n+2);
    left_stand[0] = 0;
    for (int i = 1; i<=n+1; i++)
    {
        int temp = i-1;
        while (temp!=0)
        {
            int kek = left_stand[temp];
            if (2*d[temp]<x[i]-x[kek]) temp = kek;
            else break;
        }
        left_stand[i] = temp;
    }

    if (left_stand[n+1]!=0) {cout<<0; return 0;}
    
    vector<int> right_stand(n+2);
    right_stand[n+1] = n+1;
    for (int i = n; i>=0; i--)
    {
        int temp = i+1;
        while (temp!=n+1)
        {
            int kek = right_stand[temp];
            if (2*d[temp]<x[kek]-x[i]) temp = kek;
            else break;
        }
        right_stand[i] = temp;
    }
    
    //print(left_stand);
    //print(right_stand);
    
    set<pair<double, int>> right_end;
    for (int i = 1; i<=n; i++)
    {
        if (2*d[i]>x[i]-x[left_stand[i]]) right_end.insert(mp(x[i] + 2*(d[i] - (x[i]-x[left_stand[i]])/2), i));
    }
    
    //for (auto it: right_end) cout<<it.first<<' '<<it.second<<endl;
    
    right_end.insert(mp(x[n+1], 0));
    
    set<pair<double, int>> left_end;
    for (int i = 1; i<=n; i++)
    {
        if (2*d[i]>x[right_stand[i]]-x[i]) left_end.insert(mp(x[i] - 2*(d[i] - (x[right_stand[i]]-x[i])/2), i));        
    }
    
    
    //for (auto it: left_end) cout<<it.first<<' '<<it.second<<endl;
    left_end.insert(mp(0, n+1));

    set<int> index_good;
    double minn = x[n+1]/2;
    
    for (auto it = right_end.begin(); it!=right_end.end(); it++)
    {
        while (left_end.size()>0&&left_end.begin()->first<=(it->first)) 
        {
            index_good.insert(left_end.begin()->second);
            left_end.erase(left_end.begin());
        }
        while (index_good.size()>0&&(*(index_good.begin())<=(it->second))) index_good.erase(index_good.begin());
        if (index_good.size()>0)
        {
            minn = min(minn, (x[*index_good.begin()] - x[it->second])/2);
        }
    }

    left_end.clear();
    right_end.clear();

    for (int i = 1; i<=n; i++)
    {
        if (2*d[i]>x[i]-x[left_stand[i]]) right_end.insert(mp(-(x[i] + 2*(d[i] - (x[i]-x[left_stand[i]])/2)), i));
    }
    
    right_end.insert(mp(-x[n+1], 0));
    

    for (int i = 1; i<=n; i++)
    {
        if (2*d[i]>x[right_stand[i]]-x[i]) left_end.insert(mp(-(x[i] - 2*(d[i] - (x[right_stand[i]]-x[i])/2)), i));        
    }
    
    left_end.insert(mp(0, n+1));
    
    index_good.clear();
    
    for (auto it = left_end.begin(); it!=left_end.end(); it++)
    {
        while (right_end.size()>0&&right_end.begin()->first<=(it->first)) 
        {
            index_good.insert(-(right_end.begin()->second));
            right_end.erase(right_end.begin());
        }
        while (index_good.size()>0&&(-(*(index_good.begin()))>=(it->second))) index_good.erase(index_good.begin());
        if (index_good.size()>0)
        {
            minn = min(minn, (x[it->second] - x[-(*index_good.begin())])/2);
        }
    }
    
    cout<<minn;

    
    

}