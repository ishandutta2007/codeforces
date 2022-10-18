#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<' '<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}

const int INF=1e9;

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    v(int) a(n);
    cin>>a;
    int ans=-INF;

    for(int l=0;l<n;l++)
        for(int r=l;r<n;r++)
        {
            vector<int> A,B;
            for(int i=0;i<n;i++)
                if(i<l || i>r)
                    A.push_back(a[i]);
                else
                    B.push_back(a[i]);
            sort(all(A));
            sort(all(B));
            reverse(all(A));
            int x=A.size();
            int y=B.size();
            for(int i=0;i<min(k,min(x,y));i++)
                if(A[i]>B[i])swap(A[i],B[i]);
            ans=max(ans,accumulate(all(B),0));
        }
    cout<<ans<<endl;
}