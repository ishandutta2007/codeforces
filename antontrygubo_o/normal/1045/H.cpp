#include<bits/stdc++.h>

using namespace std;

#define ll long long

const ll p = 1000000007;

vector<ll> facs(100005);

ll gcd (ll a, ll b, ll & x, ll & y) 
{
    if (a == 0) 
    {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inv(ll t)
{
    ll x, y;
    gcd(p, t, x, y);
    if (y<0) y+=p;
    return y%p;
}

ll binom(ll a, ll b)
{
    ll ans = facs[a];
    ans = (ans*inv(facs[b]))%p;
    ans = (ans*inv(facs[a-b]))%p;
    return ans;
}

ll f(ll c00, ll c01, ll c10, ll c11, bool start)
{
    if (c00<0||c01<0||c10<0||c11<0) return 0;
    if (start)
    {
        if (c10<c01) return 0;
        if (c10>c01+1) return 0;
        ll group0 = c10;
        ll group1 = c01+1;
        if (group1==0&&(c10>0||c01>0||c11>0)) return 0;
        if (group0==0&&(c00>0||c01>0||c10>0)) return 0;
        c00+=group0;
        c11+=group1;
        ll answer = 1;
        if (group0>0) answer=(answer*binom(c00-1, group0-1))%p;
        if (group1>0) answer=(answer*binom(c11-1, group1-1))%p;
        return answer;    
    } 
        
    else    
    {
        if (c01<c10) return 0;
        if (c01>c10+1) return 0;
        ll group0 = c10+1;
        ll group1 = c01;
        if (group1==0&&(c10>0||c01>0||c11>0)) return 0;
        if (group0==0&&(c00>0||c01>0||c10>0)) return 0;
        c00+=group0;
        c11+=group1;
        ll answer = 1;
        if (group0>0) answer=(answer*binom(c00-1, group0-1))%p;
        if (group1>0) answer=(answer*binom(c11-1, group1-1))%p;
        return answer;
    }
}

ll answer(ll c00, ll c01, ll c10, ll c11, string &s)
{
    ll n = c00+c01+c10+c11+1;
    if (s.length()<n) return 0;
    if (s.length()>n) return (f(c00, c01, c10, c11, 1)%p);
    ll answer = 0;
    for (int i = 1; i<n; i++)
    {
        if (s[i]=='1')
        {
            if (s[i-1]=='0') {answer+=f(c00-1, c01, c10, c11, 0); c01--;}
            else {answer+=f(c00, c01, c10-1, c11, 0); c11--;}
        }
        else
        {
            if (s[i-1]=='0') c00--;
            else c10--;
        }
        //cout<<"KEK"<<answer<<endl;
        answer%=p;
    }
    if (c00==0&&c01==0&&c10==0&&c11==0) answer = (answer+1)%p;
    return answer;
}

string m(string s)
{
    int n = s.length();
    bool cool = false;
    vector<char> kek;
    for (int i = n-1; i>=0; i--)
    {
        if (cool) kek.push_back(s[i]);
        else
        {
            if (s[i]=='1') {kek.push_back('0'); cool = true;}
            else kek.push_back('1');
        }
        //cout<<kek[n-1-i]<<' ';
    }
    string ans;
    int idx = n-1;
    if (kek[idx]=='0') idx--;
    for (int i = idx; i>=0; i--) ans += kek[i];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    facs[0] = 1;
    for (ll i = 1; i<facs.size(); i++) facs[i] = (facs[i-1]*i)%p;
    
    string a, b; 
    cin>>a>>b;
    a = m(a);
    ll c00, c01, c10, c11;
    cin>>c00>>c01>>c10>>c11;
    //cout<<answer(c00, c01, c10, c11, a)<<endl;
    //cout<<answer(c00, c01, c10, c11, b)<<endl;
    ll result = (answer(c00, c01, c10, c11, b)+p-answer(c00, c01, c10, c11, a))%p;
    cout<<result<<endl;
    
}