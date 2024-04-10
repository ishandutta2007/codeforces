#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>
#define int long long


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<" "<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;

    double cs=a*a+b*b;

    v(p(int,int)) var1,var2;
    for(int A=1;A*A+1<=a*a;A++)
    {
        int C=a*a-A*A;
        int root=sqrt(C);
        if(root*root==C)
            var1.push_back({A,root});
    }
    for(int A=1;A*A+1<=b*b;A++)
    {
        int C=b*b-A*A;
        int root=sqrt(C);
        if(root*root==C)
            var2.push_back({A,root});
    }
    int n=var1.size();
    int m=var2.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        int A=var1[i].first;
        int B=var1[i].second;
        int C=var2[j].first;
        int D=var2[j].second;
        int E=abs(B-D);
        int F=A+C;
if(B==D)
continue;
        if(E*E+F*F==a*a+b*b)
        {
            cout<<"YES"<<endl;
            cout<<0<<' '<<0<<endl;
            cout<<B<<' '<<A<<endl;
            cout<<D<<' '<<-C<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}