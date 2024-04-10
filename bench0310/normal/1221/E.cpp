#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a,b;
        string s;
        cin >> a >> b >> s;
        auto f=[&](int x)->int
        {
            if(x<b) return 1;
            else if(b<=x&&x<a) return 2;
            else if(a<=x&&x<2*b) return 3;
            else return 4;
        };
        int l=0;
        vector<int> v;
        int n=s.size();
        while(l<n)
        {
            while(l<n&&s[l]=='X') l++;
            if(l==n) break;
            int r=l;
            while(r+1<n&&s[r+1]=='.') r++;
            v.push_back(r-l+1);
            l=r+1;
        }
        bool res=[&]()->bool
        {
            array<int,5> c={0,0,0,0,0};
            for(int x:v) c[f(x)]++;
            if(c[2]>=1) return 1;
            if(c[4]>=2) return 1;
            if(c[4]==0) return ((c[3]&1)^1);
            int x=0;
            for(int y:v) if(f(y)==4) x=y;
            for(int i=1;i+a-1<=x;i++)
            {
                int one=i-1;
                int two=x-a-one;
                if(f(one)==2||f(one)==4||f(two)==2||f(two)==4) continue;
                if(((c[3]+(f(one)==3)+(f(two)==3))&1)==0) return 0;
            }
            return 1;
        }();
        if(res==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}