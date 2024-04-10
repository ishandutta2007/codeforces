#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}
bool stupid(string a, string b)
{
    map<string,int> d;
    queue<string> q;
    q.push(a);
    vector<string> go = {"AA","BB","CC","ABAB","BCBC"};
    while(q.size())
    {
        auto v=q.front();
        q.pop();
        if(v == b) return 1;
        for(int i= 0 ; i<=v.size();++i)
        {
            for(int k= 0;k< 5;++k)
            {
                string fs;
                for(int j =0; j< i;++j) fs.pbc(v[j]);
                fs += go[k];
                for(int j = i;j< v.size();++j) fs.pbc(v[j]);
                if(fs.size() <= 12) 
                {
                    if(!d.count(fs))
                    {
                        d[fs]=1;
                        q.push(fs);
                    }        
                }
            }
        }
        for(int k =0 ;k< 5;++k)
        {
            for(int j =0;j +go[k].size()-1< v.size();++j)
            {
                if( v.substr(j, go[k].size()) == go[k]) 
                {
                    string fs;
                    for(int x=0;x< j;++x) fs.pbc(v[x]);
                    for(int x=j +go[k].size();x< v.size();++x) fs.pbc(v[x]);
                    if( !d.count(fs))
                    {
                        d[fs]=1;
                        q.push(fs);
                    }
                }
            }
        }
    }
    return 0;
}
int ctp(string a)
{
    int sum =0 ;
    int c=0;
    for(int i =a.size()-1;i>=0;--i)
    {
        if( a[i] == 'C') ++c;
        else if(a[i] =='A') sum = ((sum +c) &1);
    }
    return sum;
}
vector<int> cnts(string a)
{
    vector<int> tc(3);
    for(int i=0; i< a.size();++i) tc[a[i] -'A']++;
    return tc;
}
string canon(string a)
{
    string fs;
    int cntb=0;
    for(int i =0 ;i< a.size();++i) if( a[i] == 'B')++cntb;
    if(cntb%2) fs.pbc('B');
    for(int i= 0; i< a.size();++i)
    {
        if(a[i] == 'A')
        {
            if(fs.size() && fs.back() == 'A')fs.pop_back();
            else fs.pbc('A');
        }
        else if(a[i] == 'C')
        {
            if(fs.size() && fs.back() == 'C') fs.pop_back();
            else fs.pbc('C');
        }
    }
    return fs;
}
bool smart(string a, string b)
{
    return canon(a) ==canon(b);
}
mt19937 rnd(time(0));
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    /*for(int tst=0;;++tst)
    {
        int n = rnd() % 6+1;
        string a(n,' ');
        string b(n,' ');
        for(int x=0;x< n;++x) a[x] = (char)(rnd() % 3 + 'A');
        for(int x=0 ;x< n;++x) b[x] = (char)(rnd() % 3 + 'A');
        if( smart(a,b)!= stupid(a,b))
        {
            cout<<n<<endl;
            cout<<a<<endl<<b<<endl;
            cout<<smart(a,b)<<' '<< stupid(a,b)<<endl;
            while(1);
        }
        else
        {
            cout<<"OK "<<tst<<endl;
        }
    }*/
    int t;
    cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        if(smart(s,t))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}