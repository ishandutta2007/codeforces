#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<" "<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int n,m;

int check(int x,v(int) &bad)
{
    int ret=0;
    for(int i=0;i<m;i++)
        while(!(x%bad[i]))ret--,x/=bad[i];

    for(int i=2;i*i<=x;++i)
        while(!(x%i))ret++,x/=i;
    if(x-1)
        ret++;
    return ret;
}

main()
 {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;

    v(int) a(n);
    cin>>a;
    v(int) b(m);
    cin>>b;

    int ans=0;
    for(int i=0;i<n;i++)
        ans+=check(a[i],b);
    for(int i=0;i<n;i++)
    {
        int GCD=0;
        for(int j=0;j<n-i;j++)
            GCD=gcd(GCD,a[j]);
        int win=check(GCD,b);
        if(win<0)
        {
            for(int j=0;j<n-i;j++)
                a[j]/=GCD;
            ans-=win*(n-i);
        }
    }
    cout<<ans<<endl;
}