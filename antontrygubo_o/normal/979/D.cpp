#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> divisors;

vector<int> deg;

vector<set<int>> mySet;

int gcd(int a, int b)
{
    while(a!=0&&b!=0)
    {
        if (a<b) swap(a, b);
        a = a%b;
    }
    return a+b;
}

void add (int c)
{
    if (mySet[1].find(c)==mySet[1].end())
    {
        for (int i = 0; i<divisors[c].size(); i++) mySet[divisors[c][i]].insert(c);
    }
}

int get(int x, int k, int s)
{
    if (gcd(x, k)!=k) return -1;
    int t = s-x;
    if (mySet[k].size()==0) return -1;
    int kek = *(mySet[k].begin());
    if (t<kek) return -1;
    int result = 0;
    for (int i = 17; i>=0; i--)
    {
        if ((x&deg[i])==0)
        {
            auto low = mySet[k].lower_bound(result+deg[i]);
            if (low!=mySet[k].end()&&((*low)<=min(result+2*deg[i]-1, t))) result += deg[i];
        }
        
        else
        {
            auto low = mySet[k].lower_bound(result);
            if (*low>=result+deg[i]) result+=deg[i];
            //cout<<i<<' '<<*low<<' '<<result+deg[i]-1<<endl;
        }
    }
    return result;
}

int main()
{
    
    deg.push_back(1);
    for (int i = 1; i<=17; i++)
    {
        deg.push_back(2*deg[i-1]);
    }
    
    for (int i = 0; i<=100000; i++) 
    {
        set<int> temp; mySet.push_back(temp);
    }
    for (int i = 0; i<=100000; i++) 
    {
        vector<int> temp; divisors.push_back(temp);
    }
    for (int i = 1; i<=100000; i++)
    {
        for (int j = i; j<=100000; j+=i) divisors[j].push_back(i);
    }
    //for (int i = 1; i<100000; i++) add(i);
    int q;
    cin>>q;
    int t, u;
    int x, k, s;
    for (int i = 0; i<q; i++)
    {
        cin>>t;
        if (t==1)
        {
            cin>>u;
            add(u);
        }
        else
        {
            cin>>x>>k>>s;
            cout<<get(x, k, s)<<endl;
        }
    }
    /*for (int i = 0; i<5; i++)
    {
        for (auto kek = mySet[i].begin(); kek!=mySet[i].end(); kek++)
        if (*kek!=0) cout<<*kek<<' ';
        cout<<endl;
    }
    cout<<(5&2)<<endl;*/
    
}